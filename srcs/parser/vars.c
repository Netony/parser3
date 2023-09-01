#include "parser.h"

int	ft_varsdel(char **vars, int size)
{
	int	i;

	i = 0;
	while (i < size)
		free(vars[i++]);
	free(vars);
	return (0);
}

int	ft_varsclear(char **vars)
{
	int	i;

	i = 0;
	while (vars[i])
		free(vars[i++]);
	free(vars);
	return (0);
}

int	ft_varslen(t_list *redi_list)
{
	t_redi	*redi;
	int		size;

	size = 0;
	while (redi_list)
	{
		redi = (t_redi *)(redi_list->content);
		if (ft_strcmp(redi->type, "param") == 0)
			size++;
		redi_list = redi_list->next;
	}
	return (size);
}
