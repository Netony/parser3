#include "parser.h"

char	**ft_conv_vars(t_list *redi_list)
{
	t_redi	*redi;
	char	**vars;
	int		i;

	vars = (char **)malloc(sizeof(char *) * (ft_varslen(redi_list) + 1));
	if (vars == NULL)
		return (NULL);
	i = 0;
	while (redi_list)
	{
		redi = (t_redi *)(redi_list->content);
		if (ft_strcmp(redi->type, "param") == 0)
		{
			vars[i] = ft_strdup(redi->path);
			if (vars[i] == NULL)
			{
				ft_varsdel(vars, i);
				return (NULL);
			}
			i++;
		}
		redi_list = redi_list->next;
	}
	vars[i] = NULL;
	return (vars);
}

t_list	*ft_conv_redi(t_list *redi_list)
{
	t_list	*list;
	t_list	*new;
	t_redi	*redi;
	t_redi	*redi_new;

	list = NULL;
	while (redi_list)
	{
		redi = (t_redi *)(redi_list->content);
		if (ft_strcmp(redi->type, "param"))
		{
			redi_new = ft_redicopy(redi);
			if (redi_new == NULL)
			{
				ft_lstclear(&list, (void (*)(void *))ft_redidel);
				return (NULL);
			}
			new = ft_lstnew(redi_new);
			if (new == NULL)
			{
				ft_redidel(redi_new);
				ft_lstclear(&list, (void (*)(void *))ft_redidel);
				return (NULL);
			}
			ft_lstadd_back(&list, new);
		}
		redi_list = redi_list->next;
	}
	return (list);
}
