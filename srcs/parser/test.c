#include "parser.h"
#include "test.h"
#include <stdio.h>

int	ft_print_redi(t_redi *redi)
{
	int	ret;

	ret = printf("redi->type: %s\n", redi->type);
	ret = printf("redi->path: %s\n", redi->path);
	return (ret);
}

int	ft_print_redis(t_list *redis)
{
	while (redis)
	{
		ft_print_redi(redis->content);
		printf("-------------------------\n");
		redis = redis->next;
	}
	return (0);
}

int	ft_print_cmd(t_list *cmd)
{
	int	i;

	i = 0;
	while (cmd)
	{
		printf("cmd[%d] =========================\n", i++);
		ft_print_redis(cmd->content);
		cmd = cmd->next;
	}
	return (0);
}

int	ft_print_cmds(t_cmd *cmds, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		cmd_print_vars(cmds[i].command);
		cmd_print_redi(cmds[i].redilst);
		i++;
	}
	return (0);
}

int	cmd_print_vars(char **vars)
{
	int	i;

	i = 0;
	while (vars[i])
	{
		printf("vars[%d]: %s\n", i, vars[i]);
		i++;
	}
	return (0);
}

int	cmd_print_redi(t_list *redi)
{
	t_redi	*red;

	while (redi)
	{
		red = redi->content;
		printf("type: %s, path: %s\n", red->type, red->path);
		redi = redi->next;
	}
	return (0);
}
