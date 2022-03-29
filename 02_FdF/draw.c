/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <mmaxime-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 19:11:20 by mmaxime-          #+#    #+#             */
/*   Updated: 2022/03/29 17:04:29 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_params(t_position *dots_line, t_fdf *data)
{
	int	z;
	int	z1;

	z = data->z_matrix[(int)dots_line->y][(int)dots_line->x] * data->z_zoom;
	z1 = data->z_matrix[(int)dots_line->y1][(int)dots_line->x1] * data->z_zoom;
	//---------COLOR---------
	if (z > 0 || z1 > 0)
		data->color = 0xFF0000 + (z * 20);
	else if (z < 0 || z1 < 0)
		data->color = 0x42F1B1;
	else
		data->color = 0xFFFFFF;
	//---------ZOOM---------
	dots_line->x *= data->zoom;
	dots_line->x1 *= data->zoom;
	dots_line->y *= data->zoom;
	dots_line->y1 *= data->zoom;
	//---------ISOMETRIC---------
	if (data->is_iso)
	{
		isometric(&dots_line->x, &dots_line->y, z, data->rad);
		isometric(&dots_line->x1, &dots_line->y1, z1, data->rad);
	}
	dots_line->x += data->shift_x;
	dots_line->y += data->shift_y;
	dots_line->x1 += data->shift_x;
	dots_line->y1 += data->shift_y;
}

void	bresenham(t_position dots_line, t_fdf *data)
{
	float	x_step;
	float	y_step;
	int		max;

	set_params(&dots_line, data);
	x_step = dots_line.x1 - dots_line.x;
	y_step = dots_line.y1 - dots_line.y;
	max = who_is_max(abs_value(x_step), abs_value(y_step));
	x_step /= max;
	y_step /= max;
	while((int)(dots_line.x - dots_line.x1) || (int)(dots_line.y - dots_line.y1))
	{
		my_mlx_pixel_put(&data->img, dots_line.x, dots_line.y, data->color);
		dots_line.x += x_step;
		dots_line.y += y_step;
	}
}

t_position	get_dots_line_x(t_position dots_line, int x, int y)
{
	dots_line.x = x;
	dots_line.y = y;
	dots_line.x1 = x + 1;
	dots_line.y1 = y;
	return (dots_line);
}

t_position	get_dots_line_y(t_position dots_line, int x, int y)
{
	dots_line.x = x;
	dots_line.y = y;
	dots_line.x1 = x;
	dots_line.y1 = y + 1;
	return (dots_line);
}

void	draw_line_between_dots(t_fdf *data)
{
	int			x;
	int			y;
	t_position	dots_line;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
			{
				dots_line = get_dots_line_x(dots_line, x, y);
				bresenham(dots_line, data); // draw right lines
			}
			if (y < data->height - 1)
			{
				dots_line = get_dots_line_y(dots_line, x, y);
				bresenham(dots_line, data); // draw down lines
			}
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}