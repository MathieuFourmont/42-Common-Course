/*
** SYNOPSIS: output string to given file with newline
** LIBRARY: N/A
** DESC: Outputs the string ’s’ to the given file descriptor, followed by a
** newline.
*/

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (s != NULL)
	{
		ft_putstr_fd(s, fd);
		write (fd, '\n', 1);
	}
}
