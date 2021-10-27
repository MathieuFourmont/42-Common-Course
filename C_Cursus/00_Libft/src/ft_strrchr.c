/*
** SYNOPSIS : locate character in string
** LIBRARY : <string.h>
** DESC : The strrchr() function returns a pointer to
** the last occurrence of the character c in the string s.
*/

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (s[i] == c)
			return ((char *)(s + i));
		i--;
	}
	return (0);
}
