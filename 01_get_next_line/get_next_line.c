/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:23:47 by mmaxime-          #+#    #+#             */
/*   Updated: 2021/11/10 13:55:05 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *save)
{
	size_t	len;

	len = 0;
	if (save == 0)
		return (0);
	while (save[len] != '\0')
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
	char		buffer[BUFFER_SIZE + 1];
	static char	*save[OPEN_MAX];
	int			ret;

	ret = BUFFER_SIZE;
	save[fd] = (char *)malloc(sizeof(char));
	if (fd < 0 || BUFFER_SIZE < 1 || save == NULL)
		return (0);
	save[0] = '\0';
	while (!ft_strchr(save[fd], '\n') && ret == BUFFER_SIZE)
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret == -1)
			return (0);
		else if (ret == 0)
			break ;
		buffer[ret] = '\0';
		save[fd] = ft_strjoin(save[fd], buffer);
	}
	return (ft_return_line(&save[fd]));
}
