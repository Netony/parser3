#ifndef TEST_H
# define TEST_H

# include "parser.h"
# include "redi.h"

int	ft_print_redi(t_redi *redi);
int	ft_print_redis(t_list *redis);
int	ft_print_cmd(t_list *cmd);

int	ft_print_cmds(t_cmd *cmds, int size);
int	cmd_print_vars(char **vars);
int	cmd_print_redi(t_list *redi);

# endif
