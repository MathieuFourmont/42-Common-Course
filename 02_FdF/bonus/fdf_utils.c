/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <mmaxime-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 18:24:48 by mmaxime-          #+#    #+#             */
/*   Updated: 2022/03/30 18:47:52 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	isometric(float *x, float *y, int z, float rad)
{
	int	previous_x;
	int	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(rad);
	*y = (previous_x + previous_y) * sin(rad) - z;
}

int	who_is_max(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

float	abs_value(float a)
{
	if (a < 0)
		return (-a);
	return (a);
}

void	set_default(t_fdf *data)
{
	data->zoom = 25;
	data->z_zoom = 1;
	data->shift_x = 825;
	data->shift_y = 325;
	data->rad = 0.523599;
	data->is_iso = true;
	if (data->img.img)
		mlx_destroy_image(data->mlx, data->img.img);
	data->img.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel,
			&data->img.line_lenght, &data->img.endian);
	draw_line_between_dots(data);
	print_commands(data);
}

int	close_win(t_fdf *data)
{
	(void)data;
	mlx_destroy_window(data->mlx, data->win);
	free_struct(data);
	exit(0);
	return (0);
}
