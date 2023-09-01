/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envutil.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 14:15:37 by seunghy2          #+#    #+#             */
/*   Updated: 2023/08/22 19:00:01 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	envseparate(char *nv, char **name, char **value)
{
	char	*str;
	char	*temp;

	str = ft_strdup(nv);
	if (!str)
		return ;
	temp = ft_strchr(str, '=');
	*name = str;
	*value = 0;
	if (temp)
	{
		*temp = '\0';
		*value = temp + 1;
		temp = str;
		*name = ft_strdup(temp);
		temp = *value;
		*value = ft_strdup(temp);
		free(str);
		if (!(*name) || !(*value))
		{
			freenull(name);
			freenull(value);
		}
	}
}

t_env	*envsearch(t_env *envlst, char *name)
{
	t_env	*temp;

	temp = envlst;
	while (temp && ft_strcmp(temp->name, name))
		temp = temp->next;
	return (temp);
}

void	envfree(t_env *node)
{
	if (!node)
		return ;
	free(node->name);
	free(node->value);
	free(node);
}

void	envlstfree(t_env *envlst)
{
	t_env	*tmpfree;
	t_env	*tmpnext;

	tmpfree = envlst;
	while (tmpfree)
	{
		tmpnext = tmpfree->next;
		envfree(tmpfree);
		tmpfree = tmpnext;
	}
}
