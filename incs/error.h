/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 13:11:43 by seunghy2          #+#    #+#             */
/*   Updated: 2023/08/22 18:59:41 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include <stdio.h>
# include <sys/errno.h>

# define MS_SUCCESS 0
# define MS_ERRNO 1
# define MS_MALLOC 2
# define MS_MANUAL 444
# define MS_PAST 555

void	errormsg(int errorcode, char *msg);
void	errorend(int errorcode, char *msg);

#endif
