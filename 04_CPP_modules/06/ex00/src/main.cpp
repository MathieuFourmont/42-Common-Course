/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:03:12 by marvin            #+#    #+#             */
/*   Updated: 2023/02/07 11:03:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include "../includes/convert.hpp"


int	main( int argc, char **argv )
{
	if ( argc != 2 )
	{
		std::cout << "Usage: ./convert <arg>" << std::endl;
		return ( -1 );
	}

	convert	toPrint( argv[1] );
	toPrint.printConvert();
	
	return ( 0 );
}