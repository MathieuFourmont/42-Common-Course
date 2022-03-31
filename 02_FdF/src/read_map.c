/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <mmaxime-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 12:25:35 by mmaxime-          #+#    #+#             */
/*   Updated: 2022/03/31 14:07:54 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	get_height(char *map_file)
{
	int		fd;
	char	*line;
	int		height;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		ft_error("File doesn't exist or no rights to open it");
	height = 0;
	while (get_next_line(fd, &line) > 0)
	{
		height++;
		free_ptr(&line);
	}
	free_ptr(&line);
	close(fd);
	return (height);
}

int	get_width(char *map_file)
{
	int		fd;
	char	*line;
	int		width;

	width = 0;
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		ft_error("File doesn't exist or no rights to open it");
	if (get_next_line(fd, &line) < 1)
		ft_error("Invalid file");
	width = ft_count_words(line, ' ');
	free_ptr(&line);
	close(fd);
	return (width);
}

void	malloc_matrix(t_fdf *data)
{
	int	i;

	i = 0;
	data->z_matrix = (int **)malloc(sizeof(int *) * (data->height + 1));
	if (!data->z_matrix)
		ft_error("Malloc error on matrix y axis");
	i = 0;
	while (i < data->height)
	{
		data->z_matrix[i] = (int *)malloc(sizeof(int) * (data->width + 1));
		if (!data->z_matrix[i])
			ft_error("Malloc error on matrix x axis");
		i++;
	}
}

void	fill_matrix(int *z_line, char *line)
{
	char	**num;
	int		i;

	num = ft_split(line, ' ');
	if (!num)
		ft_error("Malloc error on split");
	map_check(num);
	i = 0;
	while (num[i])
	{
		z_line[i] = ft_atoi(num[i]);
		free_ptr(&num[i]);
		i++;
	}
	free_ptr(num);
	num = NULL;
}

void	read_map(char *map_file, t_fdf *data)
{
	int		fd;
	char	*line;
	int		i;

	data->height = get_height(map_file);
	data->width = get_width(map_file);
	malloc_matrix(data);
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		ft_error("File doesn't exist or no rights to open it");
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		line_check(line, data);
		fill_matrix(data->z_matrix[i], line);
		free_ptr(&line);
		i++;
	}
	free_ptr(&line);
	close(fd);
}
