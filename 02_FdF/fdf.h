/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <mmaxime-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 11:08:15 by mmaxime-          #+#    #+#             */
/*   Updated: 2022/03/18 14:27:29 by mmaxime-         ###   ########.fr       */
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

/*
** ------------------------------ STRUCT DECLARATION ----------------------
*/

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
}				t_data;

/*
** ------------------------------ PROTOTYPES -----------------------------
*/

#endif