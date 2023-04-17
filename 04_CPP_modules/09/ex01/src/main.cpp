/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 18:15:32 by mmaxime-          #+#    #+#             */
/*   Updated: 2023/04/07 18:15:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"

int	main( int argc, char **argv )
{
	if (argc != 2 )
	{
		std::cout << "Usage: ./RPN <formula>" << std::endl;
		return ( -1 ); 
	}
	RPN	rpn( argv[1] );
	try
	{
		rpn.calculation();
	}
	catch( const std::exception& e )
	{
		std::cerr << e.what() << std::endl;
	}
	
	return ( 0 );
}