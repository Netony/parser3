/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exbuiltin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 16:04:48 by seunghy2          #+#    #+#             */
/*   Updated: 2023/08/27 15:51:30 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtincheck(char *command)
{
	if (!(ft_strcmp(command, "echo")))
		return (1);
	else if (!(ft_strcmp(command, "cd")))
		return (1);
	else if (!(ft_strcmp(command, "pwd")))
		return (1);
	else if (!(ft_strcmp(command, "export")))
		return (1);
	else if (!(ft_strcmp(command, "unset")))
		return (1);
	else if (!(ft_strcmp(command, "env")))
		return (1);
	else if (!(ft_strcmp(command, "exit")))
		return (1);
	return (0);
}

int	exbuiltin(t_exnode *arg, t_env **envlst, int noend, int outpipe)
{
	char	**command;
	int		result;

	result = -1;
	command = arg->command;
	dup2(arg->read, 0);
	if (arg->write != 1)
		dup2(arg->write, 1);
	else if (noend)
		dup2(outpipe, 1);
	if (!(ft_strcmp(command[0], "echo")))
		result = ft_echo(command);
	else if (!(ft_strcmp(command[0], "cd")))
		result = ft_cd(command, *envlst);
	else if (!(ft_strcmp(command[0], "pwd")))
		result = ft_pwd();
	else if (!(ft_strcmp(command[0], "export")))
		result = ft_export(command, envlst);
	else if (!(ft_strcmp(command[0], "unset")))
		result = ft_unset(command, envlst);
	else if (!(ft_strcmp(command[0], "env")))
		result = ft_env(*envlst);
	else if (!(ft_strcmp(command[0], "exit")))
		result = ft_exit(arg, *envlst, 0);
	return (result);
}
