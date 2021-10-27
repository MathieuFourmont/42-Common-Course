/*
** SYNOPSIS : allocate and free dynamic memory
** LIBRARY : <stdlib.h>
** DESC : The calloc() function contiguously allocates enough space for count
** objects that are size bytes of memory each and returns a pointer to the
** allocated memory. The allocated memory is filled with bytes of value zero.
*/

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*dst;

	dst = malloc(nmemb * size);
	if (dst == 0)
		return (0);
	ft_bzero(dst, nmemb * size);
	return (dst);
}
