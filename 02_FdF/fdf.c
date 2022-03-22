/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miam <miam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 11:23:03 by mmaxime-          #+#    #+#             */
/*   Updated: 2022/03/22 16:45:20 by miam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_lenght + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	close_win(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(EXIT_SUCCESS);
	return (1);
}

int	handle_keycodes(int keycode, t_vars *vars)
{
	if(keycode == 53) // = ESC
		close_win(vars);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_vars *vars)
{
	char	*str;

	str = "Hello from mouse_hook!\n";
	x = 5;
	y = 5;
	if (button == 1) // = left button of the mouse
		mlx_string_put(vars->mlx, vars->win, x, y, 0x00FF0000, str);
	return (0);
}

int	render_next_frame(t_vars *vars)
{
	t_data	img;
	int		x;
	int		y;

	x = 0;
	img.img = mlx_new_image(vars->mlx, 640, 480);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_lenght, &img.endian);
	while(x < 640)
	{
		y = 0;
		while (y < 480)
		{
			my_mlx_pixel_put(&img, x, y, 0x00FF0000);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, img.img, 0, 0);
	return (0);
}

/*int	main(void) // squares, triangles, hexagons
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

	while (y < 50 || x < 100) // diagonale rouge
	{
		my_mlx_pixel_put(&img, x, y, 0x00FF0000);
		y++;
		x += 2;
	}
	x = 5;
	y = 5;
	while (y < 50 || x < 100)
	{
		my_mlx_pixel_put(&img, x, y, 0x00FF0000);
		y++;
		x += 2;
	}
	while (y < 100 || x < 200) // diagonale verte
	{
		my_mlx_pixel_put(&img, x, y, 0x0000FF00);
		y++;
		x += 2;
	}
	x = 101;
	y = 51;
	while (y < 100 || x < 200)
	{
		my_mlx_pixel_put(&img, x, y, 0x0000FF00);
		y++;
		x += 2;
	}
	while (y < 150 || x < 400) // diagonale bleue
	{
		my_mlx_pixel_put(&img, x, y, 0x000000FF);
		y++;
		x += 2;
	}
	x = 201;
	y = 101;
	while (y < 150 || x < 400)
	{
		my_mlx_pixel_put(&img, x, y, 0x000000FF);
		y++;
		x += 2;
	}
	x = 4;
	y = 4;
	while (y > -100 || x > -200)
	{
		my_mlx_pixel_put(&img, x, y, 0x00FF0000);
		y--;
		x -= 2;
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
}

int	main(void) // circles + window closing event
{
	t_data	img;
	int		x;
	int		y;
	int		radius;
	double	distance;
	t_vars	vars;

	x = 0;
	radius = 50;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(vars.mlx, 1920, 1080);
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
	int	a;
	int	b;
	a = 500;
	b = 500;
	while (a < 550 || b < 550)
	{
		mlx_put_image_to_window(vars.mlx, vars.win, img.img, a, b);
		a += 5;
		b += 5;
	}
	mlx_hook(vars.win, 02, (1L << 2), &handle_keycodes, &vars); // 02 for keypress
	mlx_hook(vars.win, 17, (1L << 17), &close_win, &vars); // define the closing of the program by clicking the red cross of the window 
	mlx_loop(vars.mlx);
}

int	main(void) // str is appearing when a key is pressed
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
	//mlx_key_hook(vars.win, key_hook, &vars);
	mlx_mouse_hook(vars.win, &mouse_hook, &vars);
	mlx_loop(vars.mlx);
}*/

int	main()
{
	t_vars	vars;
	int	red;
	int	blue;
	int	green;

	red = 0x00FF0000;
	green = 0x0000FF00;
	blue = 0x000000FF;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
	mlx_loop_hook(vars.mlx, &render_next_frame, &vars);
	mlx_loop(vars.mlx);
}