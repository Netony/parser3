/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 15:39:32 by seunghy2          #+#    #+#             */
/*   Updated: 2023/08/27 16:31:39 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_exit(t_exnode *arg, t_env *envlst, int free)
{
	int				temp;
	unsigned char	result;
	char			**command;

	result = 0;
	command = arg->command;
	if (command && command[1])
	{
		temp = ft_atoi(command[1]);
		result = (unsigned char)temp;
	}
	if (free)
	{
		exlstfree(arg, 1);
		envlstfree(envlst);
	}
	exit(result);
}
