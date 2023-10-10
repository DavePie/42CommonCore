
#include <unistd.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s);

void    ft_putstr_fd(char *s, int fd)
{
    write(fd, s, ft_strlen(s));
}
