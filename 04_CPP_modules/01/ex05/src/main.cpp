/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:55:48 by mmaxime-          #+#    #+#             */
/*   Updated: 2022/11/02 14:55:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	Harl	harl;

	if (argc != 2)
	{
		std::cout << "Usage: ./Harl <MESSAGE>" << std::endl;
		return ( 1 );
	}
	harl.complain( argv[1] );
	return ( 0 );
}