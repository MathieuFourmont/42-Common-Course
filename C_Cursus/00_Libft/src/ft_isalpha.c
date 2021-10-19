/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 12:13:59 by mmaxime-          #+#    #+#             */
/*   Updated: 2021/10/18 12:35:55 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** SYNOPSIS : alphabetic character test
** LIBRARY : <ctype.h>
** DESC : The isalpha() function tests for any characters for which
** isupper(3) or islower(3) is true.
*/

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && <= 122))
		return (1);
	return (0);
}
