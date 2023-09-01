/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_util.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 19:17:08 by seunghy2          #+#    #+#             */
/*   Updated: 2023/08/22 19:18:30 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_UTIL_H
# define EXECUTE_UTIL_H

# include <stdlib.h>

int		ft_strcmp(const char *s1, const char *s2);
void	twodfree(char **twod);
void	freenull(char **str);

#endif
