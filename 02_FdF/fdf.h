/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <mmaxime-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 11:08:15 by mmaxime-          #+#    #+#             */
/*   Updated: 2022/03/28 15:38:47 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/*
** ------------------------------ LIBRARIES ------------------------------
*/

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include "libft/get_next_line.h"
# include <mlx.h>
# include <math.h>
# include <stdio.h>

/*
** ------------------------------ STRUCT DECLARATION ----------------------
*/

typedef	struct s_fdf
{
	//float	x;
	//float	y;
	int		width;
	int		height;
	int		**z_matrix;
	int		zoom;
	int		color;
	int		shift_x;
	int		shift_y;
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
}				t_fdf;

/*
** ------------------------------ PROTOTYPES -----------------------------
*/

void	ft_error(char *str);
void	ft_free(char **ptr);
void	read_map(char *map_file, t_fdf *data);
void	bresenham(float x, float y, float x1, float y1, t_fdf *data);
void	draw_line_between_dots(t_fdf *data);
int		close_win(t_fdf *vars);

#endif