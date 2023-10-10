#include "../libft.h"

void    ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list  *cur;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	cur = *lst;
	while (cur->next)
	{
		cur = cur->next;
	}
	cur->next = new;
}