/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <mmaxime-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 11:23:03 by mmaxime-          #+#    #+#             */
/*   Updated: 2022/03/18 15:25:06 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_lenght + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

/*int	main(void) // squares and triangles
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int	x;
	int	y;

	x = 4;
	y = 4;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_lenght, &img.endian);

	while (y < 100 || x < 200) // diagonale
	{
		my_mlx_pixel_put(&img, x, y, 0x00FF0000);
		y++;
		x += 2;
	}
	x = 5;
	y = 5;
	while (y < 100 || x < 200)
	{
		my_mlx_pixel_put(&img, x, y, 0x00FF0000);
		y++;
		x += 2;
	}
	while (y > 4)
	{
		my_mlx_pixel_put(&img, x, y, 0x00FF0000);
		y--;
		x--;
	}
	x = 5;
	y = 5;
		while (y < 100)
	{
		my_mlx_pixel_put(&img, x, y, 0x00FF0000);
		y++;
	}
	x = 5;
	y = 5;
	while (x < 100)
	{
		my_mlx_pixel_put(&img, x, y, 0x00FF0000);
		x++;
	}
	while (y < 100)
	{
		my_mlx_pixel_put(&img, x, y, 0x00FF0000);
		y++;
	}
	x = 5;
	while (x < 100 || y > 4)
	{
		my_mlx_pixel_put(&img, x, y, 0x00FF0000);
		x++;
		y--;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 500, 500);
	mlx_loop(mlx);
}*/

int	main(void) // circles
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int		x;
	int		y;
	int		radius;
	double	distance;

	x = 0;
	radius = 50;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_lenght, &img.endian);
	while (x <= 2 * radius)
	{
		y = 0;
		while (y <= 2 * radius)
		{
			distance = sqrt((double)(x - radius) * (x - radius) + (y - radius) * (y - radius)); // équation d'un cerle
			if (distance > radius - 0.5 && distance < radius + 0.5) // épaisseur du trait
				my_mlx_pixel_put(&img, x, y, 0x00FF0000);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 500, 500);
	mlx_loop(mlx);
}