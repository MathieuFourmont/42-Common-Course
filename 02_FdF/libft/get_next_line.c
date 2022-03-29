/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <mmaxime-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:23:47 by mmaxime-          #+#    #+#             */
/*   Updated: 2022/03/29 15:43:06 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	int	readed;
	int	i;

	i = 0;
	*line = malloc(4 * 1024 * 1024);
	if (!line)
		return (-1);
	readed = read(fd, *line + i, 1);
	while (readed > 0)
	{
		if ((*line)[i] == '\n')
			break ;
		i++;
		readed = read(fd, *line + i, 1);
	}
	(*line)[i] = '\0';
	return (readed);
}