/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:24:03 by mmaxime-          #+#    #+#             */
/*   Updated: 2021/11/15 14:16:45 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
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
	int		len;
	int		i;

	if (!s)
		return (0);
	len = ft_strlen(s) + 1;
	dst = (char *)malloc(sizeof(char) * len);
	if (dst == NULL)
		return (0);
	i = 0;
	while (i < len)
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_substr(char	const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	i;

	if (!s)
		return (0);
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	dst = (char *)malloc(sizeof(char) * (len + 1));
	if (dst == NULL)
		return (0);
	i = 0;
	while (i < len && s[start] != '\0')
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
