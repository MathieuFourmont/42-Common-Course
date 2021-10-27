/*
** SYNOPSIS : duplicate a string
** LIBRARY : <string.h>
** DESC : The  strdup() function returns a pointer to
** a new string which is a duplicate of the string s.
** Memory for the new string  is  obtained  with
** malloc(3), and can be freed with free(3).
*/

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dst;
	size_t	len;

	len = ft_strlen(s) + 1;
	dst = (char *)malloc(len);
	if (dst = NULL)
		return (0);
	ft_memcpy(dst, s, len);
	return (dst);
}
