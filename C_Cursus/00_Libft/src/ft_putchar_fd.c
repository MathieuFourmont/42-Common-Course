/*
** SYNOPSIS: output a character to given file
** LIBRARY: N/A
** DESC: The fputc() function writes the character c (converted to an ``unsigned
** char'') to the output stream pointed to by stream. [42 PDF] Outputs
** the character ’c’ to the given file descriptor.
*/

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}
