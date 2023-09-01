#include "parser.h"

static char	*ft_parse_type_set(const char *s, int *i);

t_list	*ft_parse_redi_list(t_info *info, const char *s, int *i)
{
	t_list	*list;
	t_list	*node;

	list = NULL;
	while (1)
	{
		*i += ft_duplen(s, *i, " ");
		if (s[*i] == '\0' || s[*i] == '|')
			break ;
		node = ft_parse_redi(info, s, i);
		if (node == NULL)
		{
			ft_lstclear(&list, (void (*))ft_redidel);
			return (NULL);
		}
		ft_lstadd_back(&list, node);
	}
	return (list);
}

t_list	*ft_parse_redi(t_info *info, const char *s, int *i)
{
	char	*type;
	t_list	*node;
	t_list	*text;
	
	type = ft_parse_type(s, i);
	if (type == NULL)
		return (NULL);
	text = ft_parse_text(info, s, i);
	if (text == NULL)
	{
		free(type);
		return (NULL);
	}
	node = ft_text_to_redi(type, text);
	//free(type);
	ft_txtclear(&text);
	if (node == NULL)
		return (NULL);
	return (node);
}

char	*ft_parse_type(const char *s, int *i)
{
	char	*type;
	
	type = ft_parse_type_set(s, i);
	if (type == NULL)
		return (NULL);
	if (s[*i] == '\0' || ft_isin(s[*i], "<>|"))
	{
		free(type);
		ft_error();
		return (NULL);
	}
	return (type);
}

static char	*ft_parse_type_set(const char *s, int *i)
{
	char	*type;

	if (ft_duplen(s, *i, "<") == 1)
	{
		*i += 1;
		type = ft_strdup("infile");
	}
	else if (ft_duplen(s, *i, ">") == 1)
	{
		*i += 1;
		type = ft_strdup("outfile");
	}
	else if (ft_duplen(s, *i, "<") > 1)
	{
		*i += 2;
		type = ft_strdup("here_doc");
	}
	else if (ft_duplen(s, *i, ">") > 1)
	{
		*i += 2;
		type = ft_strdup("append");
	}
	else
		type = ft_strdup("param");
	return (type);
}
