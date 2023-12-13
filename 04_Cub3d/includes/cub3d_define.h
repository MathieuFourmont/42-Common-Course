/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_define.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <mmaxime-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 10:34:18 by plavergn          #+#    #+#             */
/*   Updated: 2023/12/13 13:29:48 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_DEFINE_H
# define CUB3D_DEFINE_H

# define PI 3.14159265
# define TWO_PI 6.28318530
# define MINIMAP_SCALE_FACTOR 0.2
# define WIN_WIDTH 1024
# define WIN_HEIGHT 720
# define FOV_ANGLE 1.04719755 // (60 * (PI / 180))
# define NUM_RAYS WIN_WIDTH

# ifdef __linux__
#  define W 119
#  define A 97
#  define S 115
#  define D 100
#  define L_ARROW 65361
#  define R_ARROW 65363
#  define ESC 65307
# else
#  define W 13
#  define A 0
#  define S 1
#  define D 2
#  define L_ARROW 123
#  define R_ARROW 124
#  define ESC 53
# endif

# define NO 0
# define SO 1
# define EA 2
# define WE 3

# define BUFFER_SIZE 1

#endif
