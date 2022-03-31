/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <mmaxime-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 11:27:25 by mmaxime-          #+#    #+#             */
/*   Updated: 2022/03/30 19:09:14 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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
