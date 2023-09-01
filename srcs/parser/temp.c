#include "parser.h"

static char	*ft_text_join_param(t_list **text);
static char	*ft_text_join_redi(t_list **text);
t_list		*ft_redi(char *type, char *path);

char	*ft_text_join(char *type, t_list **text)
{
	char	*ret;
	if (ft_strcmp(type, "param") == 0)
		ret = ft_text_join_param(text);
	else
		ret = ft_text_join_redi(text);
	return (ret);
}

char	*ft_text_join_dquote(t_list *text)
{
	char	*join;
	char	*temp;
	char	*new;

	join = ft_strdup("");
	if (join == NULL)
		return (NULL);
	while (text)
	{
		new = ft_txtgetpath(text);
		temp = join;
		join = ft_strjoin(join, new);
		free(temp);
		if (join == NULL)
			return (NULL);
		text = text->next;
	}
	return (join);
}

t_list	*ft_text_to_redi(char *type, t_list *text)
{
	t_list	*list;
	t_list	*node;
	char	*path;

	list = NULL;
	while (text)
	{
		path = ft_text_join(type, &text);
		if (path == NULL)
		{
			ft_rediclear(&list);
			return (NULL);
		}
		node = ft_redi(type, path);
		if (node == NULL)
		{
			free(type);
			ft_rediclear(&list);
			return (NULL);
		}
		ft_lstadd_back(&list, node);
		text = text->next;
	}
	free(type);
	return (list);
}

static char	*ft_text_join_param(t_list **text)
{
	char	*join;
	char	*temp;
	char	*new;

	join = ft_strdup("");
	if (join == NULL)
		return (NULL);
	while (*text)
	{
		if (ft_txtisspace(*text))
			break ;
		new = ft_txtgetpath(*text);
		temp = join;
		join = ft_strjoin(join, new);
		free(temp);
		if (join == NULL)
			return (NULL);
		*text = (*text)->next;
	}
	return (join);
}

static char	*ft_text_join_redi(t_list **text)
{
	char	*join;
	char	*temp;
	char	*new;

	join = ft_strdup("");
	if (join == NULL)
		return (NULL);
	while (*text)
	{
		if (ft_txtisspace(*text))
		{
			ft_error();
			free(join);
			return (NULL);
		}
		new = ft_txtgetpath(*text);
		temp = join;
		join = ft_strjoin(join, new);
		free(temp);
		if (join == NULL)
			return (NULL);
		*text = (*text)->next;
	}
	return (join);
}

t_list	*ft_redi(char *type, char *path)
{
	char	*type_new;
	t_list	*redi;

	type_new = ft_strdup(type);
	if (type == NULL)
		return (NULL);
	redi = ft_redinew(type, path);
	if (redi == NULL)
	{
		free(type);
		return (NULL);
	}
	return (redi);
}
