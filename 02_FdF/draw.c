/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <mmaxime-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 19:11:20 by mmaxime-          #+#    #+#             */
/*   Updated: 2022/03/28 15:39:56 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define MAX1(a, b) (a > b ? a : b)
#define MOD(a) ((a < 0) ? -a : a)

float	mod(float i)
{
	return ((i < 0) ? -i : i);
}

void	isometric(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z;
}

void	bresenham(float x, float y, float x1, float y1, t_fdf *data)
{
	float	x_step;
	float	y_step;
	int		max;
	int		z;
	int		z1;

	z = data->z_matrix[(int)y][(int)x];
	z1 = data->z_matrix[(int)y1][(int)x1];
	//---------ZOOM---------
	x *= data->zoom;
	y *= data->zoom;
	x1 *= data->zoom;
	y1 *= data->zoom;
	//---------COLOR---------
	data->color = (z || z1) ? 0xe80c0c : 0xffffff;
	x_step = x1 - x;
	y_step = y1 - y;
	isometric(&x, &y, z);
	isometric(&x1, &y1, z1);
	x += data->shift_x;
	y += data->shift_y;
	x1 += data->shift_x;
	y1 += data->shift_y;
	x_step = x1 - x;
	y_step = y1 - y;
	max = MAX1(MOD(x_step), MOD(y_step));
	x_step /= max;
	y_step /= max;
	while((int)(x - x1) || (int)(y - y1))
	{
		mlx_pixel_put(data->img, data->win, x, y, data->color);
		x += x_step;
		y += y_step;
	}
}

void	draw_line_between_dots(t_fdf *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				bresenham(x, y, x + 1, y, data); // draw right lines
			if (y < data->height - 1)
			bresenham(x, y, x, y + 1, data); // draw down lines
			x++;
		}
		y++;
	}
	return ;
}