#include "../libft.h"
#include <stdlib>

void    ft_lstdelone(t_list *lst, void (*del)(void*))
{
    if (lst)
    {
        del(lst);
        free(lst);
    }
}