/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miam <miam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 11:23:03 by mmaxime-          #+#    #+#             */
/*   Updated: 2022/03/24 19:44:44 by miam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*int	key_handler(int key, void *data)
{
	ft_printf("%d", key);
	return (0);
}

void	set_param(t_fdf *param)
{
	param.x = 0;
}*/

int	main(int argc, char **argv)
{
	t_fdf	*data;
	
	if (argc != 2)
		ft_error("Usage: ./fdf map.fdf");
	data = (t_fdf*)malloc(sizeof(t_fdf));
	read_map(argv[1], data);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 1000, 1000, "FDF");
	data->img = mlx_new_image(data->mlx, 1000, 1000);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_lenght, &data->endian);
	bresenham(10, 10, 600, 300, data);
	//mlx_key_hook(data->win, key_handler, NULL);
	mlx_loop(data->mlx);
	return (0);
}