/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miam <miam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 11:08:15 by mmaxime-          #+#    #+#             */
/*   Updated: 2022/03/23 19:40:02 by miam             ###   ########.fr       */
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
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include "get_next_line.h"
# include <mlx.h>
# include <math.h>
# include <stdio.h>

/*
** ------------------------------ STRUCT DECLARATION ----------------------
*/

typedef	struct s_fdf
{
	float	x;
	float	y;
	float	z;
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
	int		color;
	int		width;
	int		height;
}				t_fdf;

/*
** ------------------------------ PROTOTYPES -----------------------------
*/

void	ft_perror(char *str);

#endif