/*
** SYNOPSIS: convert integer to ASCII string
** LIBRARY: N/A
** DESC: Allocates (with malloc(3)) and returns a string representing the
** integer received as an argument. Negative numbers must be handled.
*/

#include "libft.h"

void	put_zero_or_minus(int n, char *result)
{
	if (n == 0)
		result[0] = '0';
	else if (n < 0)
		result[0] = '-';
}

char	*ft_itoa(int n)
{
	long	nbr;
	long	i;
	char	*result;

	i = n < 1 ? 1 : 0;
	nbr = n < 0 ? -(long)n : (long)n;
	while (nbr != 0)
	{
		nbr /= 10;
		i++;
	}
	result = (char *)malloc(sizeof(char) * (i + 1));
	if (result == NULL)
		return (0);
	result[i] = '\0';
	nbr = n < 0 ? -(long)n : (long)n;
	while (i > 0)
	{
		result[i - 1] = nbr % 10 + 48;
		nbr /= 10;
		i--;
	}
	put_zero_or_minus(n, result);
	return (result);
}
