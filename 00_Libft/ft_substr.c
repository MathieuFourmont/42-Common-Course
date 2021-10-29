/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 10:43:06 by mmaxime-          #+#    #+#             */
/*   Updated: 2021/10/28 11:30:34 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** SYNOPSIS : extract substring from string
** LIBRARY : N/A
** DESC : Allocates (with malloc(3)) and returns a substring from the string ’s’.
** The substring begins at index ’start’ and is of maximum size ’len’.
*/

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	i;
	size_t	j;

	if (!s)
		return (0);
	dst = (char *)malloc(len + 1);
	if (dst == NULL)
		return (0);
	i = start;
	j = 0;
	while (i < ft_strlen(s) && j < len)
	{
		dst[j] = s[i];
		j++;
		i++;
	}
	dst[j] = '\0';
	return (dst);
}
