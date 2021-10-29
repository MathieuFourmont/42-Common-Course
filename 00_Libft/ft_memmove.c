/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:26:39 by mmaxime-          #+#    #+#             */
/*   Updated: 2021/10/19 16:35:54 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** SYNOPSIS : copy byte string
** LIBRARY : <string.h>
** DESC : The memmove() function copies len bytes from string src to string
** dst.  The two strings may overlap; the copy is always done in a non-
** destructive manner.
*/

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned const char	*csrc;
	unsigned char		*cdst;

	if (!dst && !src)
		return (0);
	i = 0;
	csrc = (unsigned char *)src;
	cdst = (unsigned char *)dst;
	while (i < len)
	{
		cdst[i] = csrc[i];
		i++;
	}
	return (dst);
}
