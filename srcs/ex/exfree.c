/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exfree.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 13:52:43 by seunghy2          #+#    #+#             */
/*   Updated: 2023/08/27 16:20:57 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exnodeclose(t_exnode *arg)
{
	if (arg->read != 0 && arg->read != 1)
		close(arg->read);
	if (arg->write != 0 && arg->write != 1)
		close(arg->write);
}

void	exlstfree(t_exnode *exlst, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		twodfree((exlst[i]).command);
		i++;
	}
	free(exlst);
}
