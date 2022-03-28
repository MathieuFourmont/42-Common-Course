/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <mmaxime-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 11:23:03 by mmaxime-          #+#    #+#             */
/*   Updated: 2022/03/28 15:47:41 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_handler(int key, t_fdf *data)
{
	ft_printf("%d\n", key);
	if(key == 53) // = ESC
		close_win(data);
	if (key == 126) // = Up arrow
		data->shift_y -= 10;
	if (key == 124) // = Right arrow
		data->shift_x += 10;
	if (key == 125) // Down arrow
		data->shift_y += 10;
	if (key == 123) // Left arrow
		data->shift_x -= 10;
	mlx_clear_window(data->img, data->win);
	draw_line_between_dots(data);
	return (0);
}

/*void	set_param(t_fdf *param)
{
	param.x = 0;
}*/

int	main(int argc, char **argv)
{
	t_fdf	*data;
	
	if (argc != 2)
		ft_error("Usage: ./fdf map.fdf");
	data = (t_fdf *)malloc(sizeof(t_fdf));
	if (!data)
		ft_error("malloc error on data\n");
	read_map(argv[1], data);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 1000, 1000, "FDF");
	data->zoom = 20;
	data->img = mlx_new_image(data->mlx, 1000, 1000);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_lenght, &data->endian);
	draw_line_between_dots(data);
	mlx_key_hook(data->win, key_handler, data);
	mlx_hook(data->win, 17, (1L << 17), &close_win, data);
	mlx_loop(data->mlx);
	return (0);
}