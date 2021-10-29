/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:16:16 by mmaxime-          #+#    #+#             */
/*   Updated: 2021/10/18 16:25:49 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** SYNOPSIS : size-bounded string concatenation
** LIBRARY : <string.h>
** DESC : The strlcat() function concatenate strings with the
** same input parameters and output result as snprintf(3).
** It takes the full size of the destination buffer and
** guarantee NUL-termination if there is room.  Note that
** room for the NUL should be included in dstsize.
** strlcat() appends string src to the end of dst. It will
** append at most dstsize - strlen(dst) - 1 characters.
** It will then NUL-terminate, unless dstsize is 0 or the
** original dst string was longer than dstsize (in practice
** this should not happen as it means that either dstsize is
** incorrect or that dst is not a proper string).
** If the src and dst strings overlap, the behavior is
** undefined.
*/

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_dst;
	size_t	i;

	if (dstsize <= ft_strlen(dst))
		return (dstsize + ft_strlen(src));
	len_dst = ft_strlen(dst);
	i = 0;
	while (src[i] != '\0' && len_dst + 1 < dstsize)
	{
		dst[len_dst] = src[i];
		len_dst++;
		i++;
	}
	dst[len_dst] = '\0';
	return (ft_strlen(dst) + ft_strlen(src));
}
