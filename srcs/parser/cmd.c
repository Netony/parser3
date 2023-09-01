#include "parser.h"

int	ft_cmdsdel(t_cmd *cmds, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_varsclear(cmds[i].command);
		ft_lstclear(&(cmds[i].redilst), (void (*)(void *))ft_redidel);
		i++;
	}
	free(cmds);
	return (0);
}

int	ft_cmdsize(t_list *cmd)
{
	int	size;

	size = 0;
	while (cmd)
	{
		cmd = cmd->next;
		size++;
	}
	return (size);
}
