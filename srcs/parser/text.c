#include <stdlib.h>
#include "parser.h"

int	ft_txtclear(t_list **list)
{
	ft_lstclear(list, (void (*)(void *))ft_txtdel);
	*list = NULL;
	return (0);
}

t_list	*ft_txtnew(int space, char *s)
{
	t_list	*text;
	char	*type;

	if (space)
		type = ft_strdup("space");
	else
		type = ft_strdup("text");
	text = ft_redinew(type, s);
	if (text == NULL)
		free(type);
	return (text);
}

int	ft_txtdel(t_redi *text)
{
	ft_redidel(text);
	return (0);
}

int	ft_txtisspace(t_list *text)
{
	t_redi	*redi;

	redi = (t_redi *)(text->content);
	if (ft_strcmp(redi->path, "space"))
		return (1);
	return (0);
}

char	*ft_txtgetpath(t_list *text)
{
	t_redi	*redi;

	redi = (t_redi *)(text->content);
	return (redi->path);
}
