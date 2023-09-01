/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 14:15:22 by seunghy2          #+#    #+#             */
/*   Updated: 2023/08/21 18:32:37 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include <stdlib.h>
# include <stdio.h>

typedef struct s_env
{
	char	*name;
	char	*value;
	struct s_env	*next;
}	t_env;

t_env	*envlist(char **envp);
void	envedit(t_env **envlst, char *nv);
void	envseparate(char *nv, char **name, char **value);
t_env	*envsearch(t_env *envlst, char *name);

int	ft_strcmp(const char *s1, const char *s2);

int	ft_env(t_env *envlst);
int	ft_export(char **command, t_env **envlst);
int	ft_unset(char **command, t_env **envlst);

#endif
