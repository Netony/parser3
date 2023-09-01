#include "parser.h"

t_list	*parser(t_info *info, const char *s)
{
	int	i;

	i = 0;
	i += ft_duplen(s, i, " ");
	if (s[i] == '|')
	{
		ft_error();
		return (NULL);
	}
	return (ft_parse_cmd_list(info, s, &i));
}

t_list	*ft_parse_cmd_list(t_info *info, const char *s, int *i)
{
	t_list	*node;
	t_list	*list;

	list = NULL;
	while (1)
	{
		i += ft_duplen(s, *i, " ");
		if (s[*i] == '\0')
			break ;
		node = ft_parse_cmd_node(info, s, i);
		if (node == NULL)
		{
			ft_lstclear(&list, ft_cmddel);
			return (NULL);
		}
		ft_lstadd_back(&list, node);
	}
	return (list);
}

t_list	*ft_parse_cmd_node(t_info *info, const char *s, int *i)
{
	t_list	*redi_list;
	t_list	*cmd_node;

	if (s[*i] == '|')
		*i += 1;
	*i += ft_duplen(s, *i, " ");
	if (s[*i] == '\0' || s[*i] == '|')
		return (NULL);
	redi_list = ft_parse_redi_list(info, s, i);
	if (redi_list == NULL)
		return (NULL);
	cmd_node = ft_lstnew(redi_list);
	if (cmd_node == NULL)
	{
		ft_lstclear(&redi_list, ft_redilst_del);
		return (NULL);
	}
	return (cmd_node);
}
