/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 11:59:36 by mmaxime-          #+#    #+#             */
/*   Updated: 2021/11/10 12:33:57 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*ft_return_line(char **save)
{
	char	*ret;
	char	*temp;
	int		n;

	if (!*save || **save == '\0')
		return (0);
	n = (int)((ft_strchr(*save, '\n')) - *save);
	if (ft_strchr(*save, '\n'))
	{
		ret = ft_substr(*save, 0, n + 1);
		temp = ft_substr(*save, n + 1, ft_strlen(*save));
		free (*save);
		*save = temp;
		if (**save != '\0')
			return (ret);
	}
	else
		ret = ft_strdup(*save);
	free (*save);
	*save = NULL;
	return (ret);
}

char	*get_next_line(int fd)
{
	char		*temp;
	char		*buffer;
	static char	*save[OPEN_MAX];
	int			ret;

	if (fd < 0 || BUFFER_SIZE < 1 || fd > OPEN_MAX)
		return (0);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (0);
	ret = read(fd, buffer, BUFFER_SIZE);
	while (ret > 0)
	{
		buffer[ret] = '\0';
		if (!save[fd])
			save[fd] = ft_strdup("");
		temp = ft_strjoin(save[fd], buffer);
		free (save[fd]);
		save[fd] = temp;
		if (ft_strchr(save[fd], '\n'))
			break ;
		ret = read(fd, buffer, BUFFER_SIZE);
	}
	free (buffer);
	return (ft_return_line(&save[fd]));
}
