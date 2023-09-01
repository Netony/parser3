/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 13:14:30 by seunghy2          #+#    #+#             */
/*   Updated: 2023/08/23 14:22:16 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	pwdchange(t_env *envlst)
{
	t_env	*oldpwd;
	t_env	*pwd;
	char	*present;

	present = getcwd(NULL, 0);
	if (!present)
		return (-1);
	oldpwd = envsearch(envlst, "OLDPWD");
	pwd = envsearch(envlst, "PWD");
	free(oldpwd->value);
	oldpwd->value = pwd->value;
	pwd->value = present;
	return (MS_SUCCESS);
}

int	ft_cd(char **command, t_env *envlst)
{
	int		result;
	t_env	*home;

	if (command[1])
		result = chdir(command[1]);
	else
	{
		home = envsearch(envlst, "HOME");
		result = chdir(home->value);
	}
	if (result == -1)
	{
		errormsg(MS_ERRNO, 0);
		return (-1);
	}
	result = pwdchange(envlst);
	if (result)
		errormsg(MS_ERRNO, 0);
	return (result);
}
