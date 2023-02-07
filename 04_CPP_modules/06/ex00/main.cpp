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
#include <iomanip>
#include <climits>
#include <cfloat>

int	main( int argc, char **argv )
{
	if ( argc != 2 )
	{
		std::cout << "Usage: ./convert <arg>" << std::endl;
		return ( -1 );
	}

	double	d = std::atof( argv[1] );
	int		i = static_cast<int>( d );
	float	f = static_cast<float>( d );
	char	c = static_cast<char>( d );

	std::cout << std::fixed << std::setprecision( 1 ); // pour mettre 1 chiffre apres la virgule lorsque le type le permet

	// CHAR
	if ( d > CHAR_MAX || d < CHAR_MIN )
		std::cout << "char: impossible" << std::endl;
	std::cout << "char: " << c << std::endl;


	// INT
	std::cout << "int: " << i << std::endl;


	// FLOAT
	std::cout << "float: " << f << "f" << std::endl;


	// DOUBLE
	std::cout << "double: " << d << std::endl;

	return ( 0 );
}