/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exreal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 16:05:17 by seunghy2          #+#    #+#             */
/*   Updated: 2023/08/27 14:44:42 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**pathset(t_env *envlst)
{
	char	**result;
	char	*temp;
	int		i;
	t_env	*pathnode;

	pathnode = envlst;
	while (ft_strcmp(pathnode->name, "PATH"))
		pathnode = pathnode->next;
	result = ft_split(pathnode->value, ':');
	if (!result)
		return (0);
	i = -1;
	while (result[++i])
	{
		temp = result[i];
		result[i] = ft_strjoin(temp, "/");
		if (!result[i])
		{
			result[i] = temp;
			twodfree(result);
			return (0);
		}
		free(temp);
	}
	return (result);
}

char	*pathmkr(char *origin, t_env *envlst)
{
	char	**path;
	char	*result;
	int		i;

	path = pathset(envlst);
	if (!path)
		return (0);
	result = ft_strdup(origin);
	if (!result)
		return (0);
	i = -1;
	while (path[++i] && access(result, F_OK))
	{
		free(result);
		result = ft_strjoin(path[i], origin);
		if (!result)
			return (0);
	}
	twodfree(path);
	if (!(access(result, F_OK)))
		return (result);
	free(result);
	result = ft_strdup(origin);
	return (result);
}

void	exreal(t_exnode *arg, t_env **envlst, int noend, int outpipe)
{
	int		well;
	char	*cmdpath;
	char	**envp;

	if (builtincheck((arg->command)[0]))
		exit(exbuiltin(arg, envlst, noend, outpipe));
	cmdpath = pathmkr((arg->command)[0], *envlst);
	if (!cmdpath)
		errorend(MS_MALLOC, 0);
	dup2(arg->read, 0);
	if (arg->write != 1)
		dup2(arg->write, 1);
	else if (noend)
		dup2(outpipe, 1);
	envp = envpmkr(*envlst);
	if (!envp)
		errorend(MS_MALLOC, 0);
	well = execve(cmdpath, arg->command, envp);
	if (well == -1)
		errorend(MS_ERRNO, 0);
}
