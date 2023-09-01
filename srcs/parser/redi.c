#include <stdlib.h>
#include "parser.h"

t_redi	*ft_redinew_base(char *type, char *path);

int	ft_rediclear(t_list **list)
{
	ft_lstclear(list, (void (*))ft_redidel);
	*list = NULL;
	return (0);
}

t_list	*ft_redinew(char *type, char *path)
{
	t_redi	*redi;
	t_list	*node;

	redi = ft_redinew_base(type, path);
	if (redi == NULL)
		return (NULL);
	node = ft_lstnew(redi);
	if (node == NULL)
	{
		ft_redidel(redi);
		return (NULL);
	}
	return (node);
}

t_redi	*ft_redinew_base(char *type, char *path)
{
	t_redi	*redi;

	redi = (t_redi *)malloc(sizeof(t_redi));
	if (redi == NULL)
		return (NULL);
	redi->type = type;
	redi->path = path;
	return (redi);
}

int	ft_redidel(void *param)
{
	t_redi	*redi;

	redi = (t_redi *)param;
	free(redi->type);
	free(redi->path);
	return (0);
}

t_redi	*ft_redicopy(t_redi *redi)
{
	t_redi	*copy;
	char	*type;
	char	*path;

	type = ft_strdup(redi->type);
	if (type == NULL)
		return (NULL);
	path = ft_strdup(redi->path);
	if (path == NULL)
	{
		free(type);
		return (NULL);
	}
	copy = ft_redinew_base(type, path);
	if (copy == NULL)
	{
		free(type);
		free(path);
		return (NULL);
	}
	return (copy);
}
