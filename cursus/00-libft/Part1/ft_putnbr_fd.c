#include <unistd.h>

void ft_putstr_fd(char *s, int fd);

char	*ft_itoa(int n);

void ft_putnbr_fd(int n, int fd)
{
    char    *s;

    s = ft_itoa(n);
    if (s)
    {
        ft_putstr_fd(s, fd);
        free(s);
    }
}