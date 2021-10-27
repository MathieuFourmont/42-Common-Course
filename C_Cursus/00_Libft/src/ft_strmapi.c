/*
** SYNOPSIS: create a new string from modifying string with specified function
** LIBRARY: N/A
** DESC: Applies the function ’f’ to each character of the string ’s’ to create
** a new string (with malloc(3)) resulting from successive applications of ’f’.
*/

#include "libft.h"

char	*ft_strmapi (char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int	len;
	int	i;

	i = 0;
	if (!s || !f)
		return (0);
	len = ft_strlen(s);
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (0);
	while (i < len)
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
