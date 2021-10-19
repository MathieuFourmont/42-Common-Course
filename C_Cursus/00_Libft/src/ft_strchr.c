/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 16:53:49 by mmaxime-          #+#    #+#             */
/*   Updated: 2021/10/19 17:41:22 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** SYNOPSIS : locate character in string
** LIBRARY : <string.h>
** DESC : The strchr() function locates the first occurrence of
** c (converted to a char) in the string pointed to by s. The
** terminating null character is considered to be part of the
** string; therefore if c is `\0', the functions locate the
** terminating `\0'.
*/

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while ((char)c != *s && *s != '\0')
		s++;
	if (c == *s)
		return ((char *)s);
	return (0);
}
