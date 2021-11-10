/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 12:27:23 by mmaxime-          #+#    #+#             */
/*   Updated: 2021/11/10 12:28:25 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srcsize;
	size_t	i;

	if (!dst || !src)
		return (0);
	srcsize = ft_strlen(src);
	i = 0;
	if (dstsize != 0)
	{
		while (src[i] && i < (dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (srcsize);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	int		tot_len;
	int		i;
	int		j;
	char	*join;

	if (!s1 || !s2)
		return (0);
	tot_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	join = (char *)malloc(sizeof(char) * tot_len);
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

char	*ft_strdup(const char *s)
{
	char	*dst;
	size_t	len;
	size_t	i;

	if (!s)
		return (0);
	len = ft_strlen(s) + 1;
	dst = (char *)malloc(sizeof(char) * len);
	if (dst == NULL)
		return (0);
	i = 0;
	while (i < len)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)s)[i];
		i++;
	}
	return (dst);
}

char	*ft_substr(char	const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	i;
	size_t	end;

	if (!s)
		return (0);
	end = 0;
	if (start < ft_strlen(s))
		end = ft_strlen(s) - start;
	if (end > len)
		end = len;
	dst = (char *)malloc(sizeof(char) * (end + 1));
	if (dst == NULL)
		return (0);
	i = 0;
	while (i < len && start < ft_strlen(s))
	{
		dst[i] = s[start];
		i++;
		start++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s || c == '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (0);
}
