#include "parser.h"

t_list	*ft_parse_dquote_env(t_info *info, const char *s, int *i);

t_list	*ft_parse_text(t_info *info, const char *s, int *i)
{
	t_list	*node;
	t_list	*list;
	
	*i += ft_duplen(s, *i, " ");
	list = NULL;
	while (1)
	{
		if (s[*i] == '\0' || ft_isin(s[*i], " <>|"))
			break ;
		else if (s[*i] == '\'')
			node = ft_parse_quote(s, i);
		else if (s[*i] == '\"')
			node = ft_parse_dquote(info, s, i);
		else if (s[*i] == '$')
			node = ft_parse_env(info, s, i);
		else 
			node = ft_parse_tok(s, i, "\'\" <|>");
		if (node == NULL)
		{
			ft_txtclear(&list);
			return (NULL);
		}
		ft_lstadd_back(&list, node);
	}
	return (list);
}

t_list	*ft_parse_dquote(t_info *info, const char *s, int *i)
{
	t_list	*list;
	t_list	*node;

	*i += 1;
	if (ft_toklen_zero(s, *i, "\"") < 0)
	{
		ft_error();
		return (NULL);
	}
	list = NULL;
	while (s[*i] && s[*i] != '\"')
	{
		if (s[*i] == '$')
			node = ft_parse_dquote_env(info, s, i);
		else 
			node = ft_parse_tok(s, i, "$\"");
		if (node == NULL)
		{
			ft_lstclear(&list, free);
			return (NULL);
		}
		ft_lstadd_back(&list, node);
	}
	*i += 1;
	return (list);
}

t_list	*ft_parse_dquote_env(t_info *info, const char *s, int *i)
{
	t_list	*text;
	t_list	*node;
	char	*ret;

	text = ft_parse_env(info, s, i);
	if (text == NULL)
		return (NULL);
	ret = ft_text_join_dquote(text);
	if (ret == NULL)
	{
		ft_txtclear(&text);
		return (NULL);
	}
	node = ft_lstnew(ret);
	if (node == NULL)
	{
		free(ret);
		return (NULL);
	}
	return (node);
}

t_list	*ft_parse_quote(const char *s, int *i)
{
	t_list	*node;

	*i += 1;
	if (ft_toklen_zero(s, *i, "\'") < 0)
	{
		ft_error();
		return (NULL);
	}
	node = ft_parse_tok(s, i, "\'");
	*i += 1;
	return (node);
}

t_list	*ft_parse_tok(const char *s, int *i, const char *set)
{
	t_list	*node;
	char	*text;
	int		len;

	len = ft_toklen(s, *i, set);
	text = ft_substr(s, *i, len);
	if (text == NULL)
		return (NULL);
	node = ft_txtnew(0, text);
	if (node == NULL)
	{
		free(text);
		return (NULL);
	}
	*i += len;
	return (node);
}
