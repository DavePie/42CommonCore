#include "../libft.h"
#include <stdlib>

void ft_lstclear(t_list **lst, void (*del)(void*))
{
    t_list  *cur;
    t_list  *temp;

    cur = *lst;
    while(cur)
    {
        temp = cur;
        cur = cur->next;
        del(cur);
        free(cur);
    }
    *lst = 0;
}