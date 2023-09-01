#include "parser.h"

void	ft_cmd_node_del(void *node);
void	ft_redilst_del(void *redilst);

int	ft_error(void)
{
	return (ft_putendl_fd("ERROR", 2));
}

void	ft_cmddel(void *lst)
{
	t_list	*cmd_list;

	cmd_list = (t_list *)lst;
	ft_lstclear(&cmd_list, (void (*)(void *))ft_redilst_del);
}

void	ft_redilst_del(void *redilst)
{
	t_list	*redi_list;

	redi_list = (t_list *)redilst;
	ft_lstclear(&redi_list, (void (*)(void *))ft_redidel);
}
