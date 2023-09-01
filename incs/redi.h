#ifndef REDI_H
# define REDI_H

typedef struct s_redi
{
	char	*type;
	char	*path;
}	t_redi;

t_list	*ft_redinew(char *type, char *path);
int		ft_rediclear(t_list **list);
int		ft_redidel(void *param);

t_redi	*ft_redicopy(t_redi *redi);

t_list	*ft_txtnew(int space, char *s);
int		ft_txtclear(t_list **list);
int		ft_txtdel(t_redi *text);

int		ft_txtisspace(t_list *text);
char	*ft_txtgetpath(t_list *text);

#endif
