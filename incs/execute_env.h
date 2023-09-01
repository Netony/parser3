/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_env.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 14:19:28 by seunghy2          #+#    #+#             */
/*   Updated: 2023/08/31 14:07:21 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_ENV_H
# define EXECUTE_ENV_H

# include <stdlib.h>
# include <stdio.h>

typedef struct s_env
{
	char			*name;
	char			*value;
	struct s_env	*next;
}	t_env;

typedef struct s_info
{
	t_env	*envlst;
	int		status;
	pid_t	lastpid;
}	t_info;
// 현재 프로세스의 pid 구할 수 있을 시, builtin 함수를 쓸 때에는 어떻게 되는 지 확인하기.

t_env	*envlist(char **envp);
int		envadd(t_env **envlst, char *nv);
void	envdelete(t_env **envlst, char *name);
void	envseparate(char *nv, char **name, char **value);
t_env	*envsearch(t_env *envlst, char *name);
void	envfree(t_env *node);
void	envlstfree(t_env *envlst);
char	**envpmkr(t_env *envlst);

int		ft_env(t_env *envlst);
int		ft_export(char **command, t_env **envlst);
int		ft_unset(char **command, t_env **envlst);

#endif
