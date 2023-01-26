/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <mmaxime-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:10:07 by mmaxime-          #+#    #+#             */
/*   Updated: 2022/12/05 10:10:07 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

void	ft_conversion( char *str )
{
	int	i;

	i = 0;
	while (str[i])
	{
			std::cout << (char)toupper(str[i]);
			i++;
	}
}

int main( int argc, char **argv )
{
	int i;

	i = 1;
	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		while (i < argc)
		{
			ft_conversion(argv[i]);
			i++;
		}
	}
	std::cout << std::endl;
	return (0);
}
