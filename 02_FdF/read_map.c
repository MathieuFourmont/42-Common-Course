/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miam <miam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 12:25:35 by mmaxime-          #+#    #+#             */
/*   Updated: 2022/03/24 20:04:50 by miam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_count_words(char const *str, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while(str[i])
	{
		while (str[i] == c && str[i] != '\0')
			i++;
		if (str[i])
			words++;
		while (str[i] == c && str[i] != '\0')
			i++;
	}
	return (words);
}

int	get_height(char *map_file)
{
	int		fd;
	char	*line;
	int		height;

	if ((fd = open(map_file, O_RDONLY, 0)) <= 0)
		ft_error("Could not open the file");
	height = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		height++;
		ft_free(&line);
		line = get_next_line(fd);
	}
	ft_free(&line);
	close(fd);
	return (height);
}

int	get_widh(char *map_file)
{
	int		fd;
	char	*line;
	int		width;

	if ((fd = open(map_file, O_RDONLY, 0)) <= 0)
		ft_error("Could not open the file");
	line = get_next_line(fd);
	width = ft_count_words(line, ' ');
	ft_free(&line);
	close(fd);
	return (width);
}

void	fill_matrix(int *z_line, char *line)
{
	char	**num;
	int		i;

	num = ft_split(line, ' ');
	i = 0;
	while (num[i])
	{
		z_line[i] = ft_atoi(num[i]);
		ft_free(&num[i]);
		i++;
	}
	ft_free(num);
}

void	read_map(char *map_file, t_fdf *data)
{
	int		fd;
	char	*line;
	int		i;
	
	data->height = get_height(map_file);
	data->width = get_widh(map_file);
	data->z_matrix = (int **)malloc(sizeof(int*) * (data->height + 1));
	i = 0;
	while (i <= data->height)
		data->z_matrix[i++] = (int*)malloc(sizeof(int) * (data->width + 1));
	if ((fd = open(map_file, O_RDONLY, 0)) <= 0)
		ft_error("Could not open the file");
	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		fill_matrix(data->z_matrix[i], line);
		ft_free(&line);
		i++;
		line = get_next_line(fd);
	}
	ft_free(&line);
	close(fd);
	data->z_matrix[i] = NULL;
}