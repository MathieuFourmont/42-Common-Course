/*
** SYNOPSIS : locate a substring in a string
** LIBRARY : <string.h>
** DESC : The strnstr() function locates the first occurence
** of the null-terminated string little in the string big,
** where not more than len characters are searched. Characters
** that appear after a '\0' character are not searched.
*/

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	h;
	size_t	n;

	h = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[h] != '\0')
	{
		n = 0;
		while (big[h + n] == little[n] && (h + n) < len)
		{
			if (big[h + n] == '\0' && little[n] == '\0')
				return ((char *)&big[h]);
			n++;
		}
		if (little[n] == '\0')
			return ((char *)big + h);
		h++;
	}
	return (0);
}
