/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <mmaxime-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:23:10 by mmaxime-          #+#    #+#             */
/*   Updated: 2022/03/30 18:48:02 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	free_ptr(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
}

void	free_struct(t_fdf *data)
{
	int	i;

	i = 0;
	while (i < data->height)
	{
		free(data->z_matrix[i]);
		i++;
	}
	free(data->z_matrix);
	free(data);
}

void	freetab(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		free_ptr(&argv[i]);
		i++;
	}
	free(argv);
	argv = NULL;
}
