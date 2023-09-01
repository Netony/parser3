/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 16:04:40 by seunghy2          #+#    #+#             */
/*   Updated: 2023/08/27 15:59:53 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX_h
# define EX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_exnode
{
	int	read;
	int	write;
	char	**command;
}	t_exnode;

typedef struct s_redi
{
	char	*type;
	char	*path;
}	t_redi;

typedef struct s_list
{
	void	*content;
	struct s_list	*next;
}	t_list;

typedef struct s_cmd
{
	t_list	*redilst;
	char	**command;
}	t_cmd;

typedef struct s_env
{
	char	*name;
	char	*value;
	struct s_env	*next;
}	t_env;

void		piping(t_cmd *lst, int size, t_env **envlst);
int			exnodeset(t_exnode *arg, t_cmd node, int inpipe);
void		exreal(t_exnode *arg, t_env **envlst, int noend, int outpipe);
int			exbuiltin(t_exnode *arg, t_env **envlst, int noend, int outpipe);

char	*get_next_line(int fd);
int	ft_strcmp(const char *s1, const char *s2);
void	twodfree(char **twod);

#endif
