/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <mmaxime-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 14:31:45 by mmaxime-          #+#    #+#             */
/*   Updated: 2022/03/31 11:59:40 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	translation(int key, t_fdf *data)
{
	if (key == 126)
		data->shift_y -= 15;
	if (key == 124)
		data->shift_x += 15;
	if (key == 125)
		data->shift_y += 15;
	if (key == 123)
		data->shift_x -= 15;
	if (data->img.img)
		mlx_destroy_image(data->mlx, data->img.img);
	data->img.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel,
			&data->img.line_lenght, &data->img.endian);
	draw_line_between_dots(data);
	print_commands(data);
}

void	zoom_map(int key, t_fdf *data)
{
	if (key == 69 || key == 24)
		data->zoom += 1;
	if ((key == 78 || key == 27) && data->zoom > 1)
		data->zoom -= 1;
	if (data->img.img)
		mlx_destroy_image(data->mlx, data->img.img);
	data->img.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel,
			&data->img.line_lenght, &data->img.endian);
	draw_line_between_dots(data);
	print_commands(data);
}

void	set_projection(int key, t_fdf *data)
{
	if (key == 34)
		data->is_iso = true;
	if (key == 35)
		data->is_iso = false;
	if (data->img.img)
		mlx_destroy_image(data->mlx, data->img.img);
	data->img.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel,
			&data->img.line_lenght, &data->img.endian);
	draw_line_between_dots(data);
	print_commands(data);
}

void	rotate_model(int key, t_fdf *data)
{
	data->is_iso = true;
	if (key == 43)
		data->rad -= 0.1;
	if (key == 47)
		data->rad += 0.1;
	if (data->img.img)
		mlx_destroy_image(data->mlx, data->img.img);
	data->img.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel,
			&data->img.line_lenght, &data->img.endian);
	draw_line_between_dots(data);
	print_commands(data);
}

void	zoom_z(int key, t_fdf *data)
{
	if (key == 6)
		data->z_zoom += 1;
	if (key == 7 && data->zoom > 1)
		data->z_zoom -= 1;
	if (data->img.img)
		mlx_destroy_image(data->mlx, data->img.img);
	data->img.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel,
			&data->img.line_lenght, &data->img.endian);
	draw_line_between_dots(data);
	print_commands(data);
}
