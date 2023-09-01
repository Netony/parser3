#include "parser.h"

t_list	*ft_parse_space(const char *s, int *i);
int		env_key_size(const char *s, int *i);
char	*env_get_key(const char *s, int start, int size);
t_list	*env_get_value(t_info *info, char *key);
t_list	*env_get_status(t_info *info);

t_list	*ft_parse_env(t_info *info, const char *s, int *i)
{
	int		size;
	char	*key;
	char	*temp;
	t_list	*value;

	*i += 1;
	size = env_key_size(s, i);
	if (size >= 0)
	{
		key = env_get_key(s, *i, size);
		if (key == NULL)
			return (NULL);
		free(key);
		value = env_get_value(info, key);
		if (value == NULL)
			return (NULL);
		*i += size;
	}
	else
	{
		temp = ft_strdup("$");
		if (temp == NULL)
			return (NULL);
		value = ft_lstnew(temp);
		if (value == NULL)
		{
			free(temp);
			return (NULL);
		}
	}
	return (value);
}

int	env_key_size(const char *s, int *i)
{
	int	len;

	len = ft_toklen(s, *i, "?\"\'$ <|>");
	if (len == 0)
	{
		if (s[*i] == '?')
			len += 1;
		else if (s[*i] == ' ' || s[*i] == '\0')
			len = -1;
	}
	return (len);
	/*
	else if (s[*i] == '$')
		len = 1;
		*/
	return (len);
}

char	*env_get_key(const char *s, int start, int size)
{
	return (ft_substr(s, start, size));
}

t_list	*env_get_value(t_info *info, char *key)
{
	t_env	*node;
	char	*dup;
	t_list	*new;
	t_list	*list;
	int		i;
	
	/*
	else if (ft_strcmp(key, "$") == 0)
		value = ft_getenv_pid();
	// key == "" ?
	*/
	list = NULL;
	if (ft_strcmp(key, "?") == 0)
		list = env_get_status(info);
	else
	{
		node = envsearch(info->envlst, key);
		if (node == NULL)
			dup = ft_strdup("");
		else
			dup = ft_strdup(node->value);
		i = 0;
		while (dup[i])
		{
			if (dup[i] == ' ')
				new = ft_parse_space(dup, &i);
			else
				new = ft_parse_tok(dup, &i, " ");
			if (new == NULL)
			{
				ft_txtclear(&list);
				return (NULL);
			}
			ft_lstadd_back(&list, new);
		}
	}
	return (list);
}

t_list	*env_get_status(t_info *info)
{
	char	*status;
	t_list	*node;

	(void)info;
	status = ft_strdup("0");
	if (status == NULL)
		return (NULL);
	node = ft_lstnew(status);
	if (node == NULL)
	{
		free(status);
		return (NULL);
	}
	return (node);
}

t_list	*ft_parse_space(const char *s, int *i)
{
	t_list	*node;
	char	*text;
	int		len;

	len = ft_duplen(s, *i, " ");
	text = ft_substr(s, *i, len);
	if (text == NULL)
		return (NULL);
	node = ft_txtnew(1, text);
	if (node == NULL)
	{
		free(text);
		return (NULL);
	}
	*i += len;
	return (node);
}
