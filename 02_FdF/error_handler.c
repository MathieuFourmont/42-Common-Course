/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <mmaxime-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 18:02:08 by mmaxime-          #+#    #+#             */
/*   Updated: 2022/03/29 15:48:32 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_error(char *str)
{
	ft_printf("%s\n", str);
	exit (1);
}

int	maplen(char **num)
{
	int	len;

	len = 0;
	while (num[len])
		len++;
	return (len);
}

int	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '0' && str[1] == '0')
		return (0);
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	if (i == 1 && (str[0] == '-' || str[0] == '+'))
		return (0);
	return (1);
}

void	map_check(char **num)
{
// Check if the map is valid for our program
// Will then split the parsed numbers et do the check
// If error -> free & exit
	char	**tmp;
	int		map_len;
	int		i;

	i = 0;
	map_len = maplen(num);
	while (i < map_len)
	{
		tmp = ft_split(num[i], ',');
		if (!is_number(tmp[0]))
		{
			i = 0;
			while (num[i])
			{
				free(num[i]);
				i++;
			}
			free(num);
			freetab(tmp);
			ft_error("Invalid map");
		}
		i++;
		freetab(tmp);
	}
}