/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 14:16:03 by seunghy2          #+#    #+#             */
/*   Updated: 2023/08/27 16:31:13 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_export(char **command, t_env **envlst)
{
	int		i;
	t_env	*temp;

	i = 0;
	while (command[++i])
	{
		if (envadd(envlst, command[i]))
		{
			errormsg(MS_MALLOC, 0);
			return (-1);
		}
	}
	if (i == 1)
	{
		temp = *envlst;
		while (temp)
		{
			printf("%s", temp->name);
			if (temp->value)
				printf("=%s", temp->value);
			printf("\n");
			temp = temp->next;
		}
	}
	return (0);
}
