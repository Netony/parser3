/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 14:15:53 by seunghy2          #+#    #+#             */
/*   Updated: 2023/08/28 18:49:56 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	choldpwd(t_env **result)
{
	t_env	*oldpwd;
	int		end;

	oldpwd = envsearch(*result, "OLDPWD");
	if (oldpwd)
		freenull(&(oldpwd->value));
	else
	{
		end = envadd(result, "OLDPWD");
		if (end)
		{
			envlstfree(*result);
			errorend(MS_MALLOC, 0);
		}
	}
}

t_env	*envlist(char **envp)
{
	t_env	*result;
	t_env	**temp;
	int		i;

	i = -1;
	temp = &result;
	while (envp[(++i) + 1])
	{
		*temp = (t_env *)malloc(sizeof(t_env));
		if (!(*temp))
		{
			envlstfree(result);
			errorend(MS_MALLOC, 0);
		}
		envseparate(envp[i], &((*temp)->name), &((*temp)->value));
		(*temp)->next = 0;
		if (!((*temp)->name))
		{
			envlstfree(result);
			errorend(MS_MALLOC, 0);
		}
		temp = &((*temp)->next);
	}
	choldpwd(&result);
	return (result);
}

int	envchange(t_env *envlst, char *name, char *value)
{
	t_env	*node;

	node = envsearch(envlst, name);
	if (node)
	{
		if (value)
		{
			free(node->value);
			node->value = value;
		}
		return (1);
	}
	return (0);
}

int	envadd(t_env **envlst, char *nv)
{
	t_env	*temp;
	char	*name;
	char	*value;

	envseparate(nv, &name, &value);
	if (!name)
		return (MS_MALLOC);
	if (envchange(*envlst, name, value))
	{
		free(name);
		return (MS_SUCCESS);
	}
	temp = (t_env *)malloc(sizeof(t_env));
	if (!temp)
	{
		free(name);
		free(value);
		return (MS_MALLOC);
	}
	temp->name = name;
	temp->value = value;
	temp->next = *envlst;
	*envlst = temp;
	return (MS_SUCCESS);
}

void	envdelete(t_env **envlst, char *name)
{
	t_env	*temp1;
	t_env	*temp2;

	temp1 = *envlst;
	if (!temp1)
		return ;
	else if (!(ft_strcmp(temp1->name, name)))
	{
		*envlst = temp1->next;
		envfree(temp1);
		return ;
	}
	while (temp1->next && ft_strcmp(temp1->next->name, name))
		temp1 = temp1->next;
	if (!(temp1->next))
		return ;
	temp2 = temp1->next->next;
	envfree(temp1->next);
	temp1->next = temp2;
}
