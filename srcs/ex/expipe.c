/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expipe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 16:05:07 by seunghy2          #+#    #+#             */
/*   Updated: 2023/08/31 14:05:43 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	waiting(void)
{
	pid_t	pid;

	pid = 1;
	while (pid != -1)
		pid = waitpid(0, 0, WNOHANG);
}

void	argfree(t_exnode *arg)
{
	if (arg->read != 0)
		close(arg->read);
	if (arg->write != 1)
		close(arg->write);
	free(arg);
}

pid_t	nodepipefork(t_cmd origin, int fd[2], t_exnode *arg, pid_t *pid)
{
	pid_t	past;

	past = *pid;
	if (exnodeset(arg, origin, fd[0]))
	{
		errormsg(MS_ERRNO, 0);
		return (past);
	}
	if (pipe(fd) == -1)
	{
		exnodeclose(arg);
		errormsg(MS_ERRNO, 0);
		return (past);
	}
	*pid = fork();
	if (*pid == -1)
	{
		exnodeclose(arg);
		close(fd[0]);
		close(fd[1]);
		errormsg(MS_ERRNO, 0);
		return (past);
	}
	return (0);
}

pid_t	expipe(t_exnode *arg, t_cmd *lst, int size, t_env **envlst)
{
	int			fd[2];
	pid_t		pid;
	int			i;
	pid_t		expid;

	i = 0;
	fd[0] = 0;
	pid = 0;
	expid = nodepipefork(lst[i], fd, &(arg[i]), &pid);
	if (expid)
		return (expid);
	while (pid && i < size - 1)
	{
		close(fd[1]);
		exnodeclose(&(arg[i]));
		i++;
		expid = nodepipefork(lst[i], fd, &(arg[i]), &pid);
		if (expid)
			return (expid);
	}
	close(fd[0]);
	if (!pid)
		exreal(&(arg[i]), envlst, size - i - 1, fd[1]);
	exnodeclose(&(arg[i]));
	return (pid);
}

void	piping(t_cmd *lst, int size, t_info *info)
{
	t_exnode	*exlst;
	int			i;

	exlst = (t_exnode *)malloc(sizeof(t_exnode) * size);
	if (!exlst)
		errormsg(MS_MALLOC, 0);
	i = 0;
	while (i < size)
	{
		(exlst[i]).command = (lst[i]).command;
		i++;
	}
	info->lastpid = expipe(exlst, lst, size, &(info->envlst));
	exlstfree(exlst, size);
	waitpid(info->lastpid, &(info->status), 0);
	waiting();
}
