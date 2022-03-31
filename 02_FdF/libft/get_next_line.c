/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <mmaxime-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:23:47 by mmaxime-          #+#    #+#             */
/*   Updated: 2022/03/30 16:54:10 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	int	read_line;
	int	i;

	i = 0;
	*line = malloc(4 * 1024 * 1024);
	if (!line)
		return (-1);
	read_line = read(fd, *line + i, 1);
	while (read_line > 0)
	{
		if ((*line)[i] == '\n')
			break ;
		i++;
		read_line = read(fd, *line + i, 1);
	}
	(*line)[i] = '\0';
	return (read_line);
}
