/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <mmaxime-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 11:23:03 by mmaxime-          #+#    #+#             */
/*   Updated: 2022/03/29 17:11:16 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_handler(int key, t_fdf *data)
{
	//ft_printf("%d\n", key);
	if(key == 53) // = ESC
	{
		free_struct(data);
		exit(0);
	}
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		dst = data->addr + (y * data->line_lenght
		+ x * (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	init_data(t_fdf *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "FDF / mmaxime-");
	data->img.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel,
	&data->img.line_lenght, &data->img.endian);
	data->zoom = 25;
	data->z_zoom = 1;
	data->shift_x = 825;
	data->shift_y = 325;
	data->rad = 0.523599;
	data->is_iso = true;
	draw_line_between_dots(data);
}

int	main(int argc, char **argv)
{
	t_fdf	*data;
	
	if (argc != 2)
		ft_error("Usage: ./fdf map.fdf");
	data = (t_fdf *)malloc(sizeof(t_fdf));
	if (!data)
		ft_error("Malloc error on data");
	read_map(argv[1], data);
	init_data(data);
	mlx_hook(data->win, 17, (1L << 17), &close_win, data);
	mlx_hook(data->win, 2, 0, key_handler, data);
	mlx_loop(data->mlx);
	return (0);
}