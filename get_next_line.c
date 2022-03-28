/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <mmaxime-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:23:47 by mmaxime-          #+#    #+#             */
/*   Updated: 2022/03/28 12:08:25 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_free(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
}

char	*ft_return_line(char **save, char *temp, int new_line_index)
{
	char	*ret;

	if (new_line_index < 0)
	{
		if (!**save && !temp)
		{
			free(*save);
			*save = NULL;
			return (NULL);
		}
		ret = ft_strdup(*save);
		free(*save);
		*save = NULL;
		return (ret);
	}
	*save = ft_substr(temp, new_line_index + 1, ft_strlen(temp));
	temp[new_line_index + 1] = '\0';
	ret = temp;
	temp = NULL;
	return (ret);
}

char	*ft_get_line(int fd, char **save, char *buffer)
{
	int		ret;
	char	*temp;
	char	*find_new_line;
	int		new_line_position;

	temp = NULL;
	find_new_line = ft_strchr(*save, '\n');
	while (find_new_line == 0)
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret < 1)
			return (ft_return_line(save, temp, -1));
		buffer[ret] = '\0';
		temp = ft_strjoin(*save, buffer);
		ft_free(save);
		*save = temp;
		find_new_line = ft_strchr(*save, '\n');
	}
	temp = *save;
	new_line_position = 0;
	while (temp[new_line_position] != '\n')
		new_line_position++;
	return (ft_return_line(save, temp, new_line_position));
}

char	*get_next_line(int fd)
{
	static char	*save[OPEN_MAX];
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1 || fd > OPEN_MAX)
		return (0);
	if (!save[fd])
		save[fd] = ft_strdup("");
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (0);
	line = ft_get_line(fd, &save[fd], buffer);
	ft_free(&buffer);
	return (line);
}