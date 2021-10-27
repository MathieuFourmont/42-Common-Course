/*
** SYNOPSIS: output string to given file
** LIBRARY: N/A
** DESC: Outputs the string ’s’ to the given file descriptor.
*/

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (s != NULL)
	{
		i = 0;
		while (s[i])
		{
			write (fd, &s[i], 1);
			i++;
		}
	}
}
