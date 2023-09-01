#ifndef PARSER_H
# define PARSER_H

#include <stdio.h>
#include "../libft/incs/libft.h"
#include "execute_env.h"
#include "redi.h"

typedef struct s_cmd
{
	t_list	*redilst;
	char	**command;
}	t_cmd;

int		ft_cmdsdel(t_cmd *cmds, int size);
int		ft_cmdsclear(t_cmd *cmds);

int		ft_cmdsize(t_list *cmd);
void	ft_cmddel(void *lst);
int		ft_error(void);
void	ft_redilst_del(void *redilst);

t_list	*parser(t_info *info, const char *s);
t_list	*ft_parse_cmd_list(t_info *info, const char *s, int *i);
t_list	*ft_parse_cmd_node(t_info *info, const char *s, int *i);

t_list	*ft_parse_redi_list(t_info *info, const char *s, int *i);
t_list	*ft_parse_redi(t_info *info, const char *s, int *i);
char	*ft_parse_type(const char *s, int *i);

t_list	*ft_parse_text(t_info *info, const char *s, int *i);

t_list	*ft_parse_dquote(t_info *info, const char *s, int *i);
t_list	*ft_parse_quote(const char *s, int *i);
t_list	*ft_parse_tok(const char *s, int *i, const char *set);
t_list	*ft_parse_env(t_info *info, const char *s, int *i);

t_list	*ft_text_to_redi(char *type, t_list *text);
char	*ft_text_join_dquote(t_list *text);
char	*ft_lstjoin(t_list *lst);

int		ft_isin(int a, const char *set);
int		ft_toklen(const char *s, int start, const char *set);
int		ft_toklen_zero(const char *s, int start, const char *set);
int		ft_duplen(const char *s, int start, const char *set);

t_cmd	*ft_convert(t_list *list);
t_list	*ft_conv_redi(t_list *redi_list);
char	**ft_conv_vars(t_list *node);
int		ft_varslen(t_list *node);
int		ft_varsclear(char **vars);
int		ft_varsdel(char **vars, int size);

int		ft_strcmp(const char *s1, const char *s2);

#endif
