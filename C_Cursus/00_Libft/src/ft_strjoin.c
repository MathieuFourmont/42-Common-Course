/*
** SYNOPSIS : concatenate two strings into a new string (with malloc)
** LIBRARY : N/A
** DESC : Allocates (with malloc(3)) and returns a new string,
** which is the result of the concatenation of ’s1’ and ’s2’.
*/

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int	tot_len;
	int	i;
	int	j;
	char	*join;

	if (s1[0] == '\0' || s2[0] == '\0')
		return (0);
	tot_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	join = (char *)malloc(sizeof(join) * tot_len);
	if (join == NULL)
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		join[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
		join[i++] = s2[j++];
	join[i] = '\0';
	return (join);
}
