/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <mmaxime-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 16:04:36 by mmaxime-          #+#    #+#             */
/*   Updated: 2023/04/17 16:04:36 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"

int	main( int argc, char **argv )
{
	BitcoinExchange	btc;

	if ( argc != 2 )
		{
			std::cerr << "Usage: ./btc <filename>." << std::endl;
			return ( -1 );
		}
	try
	{
		btc.mapCreation( "data.csv" );
		btc.printValo( argv[1] );
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return ( 0 );
}