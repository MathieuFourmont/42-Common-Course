/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 17:33:36 by mmaxime-          #+#    #+#             */
/*   Updated: 2023/02/03 17:33:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include "../includes/Bureaucrat.hpp"

int	main()
{
	try
	{
		Bureaucrat	b( "Mathieu", 2 );
		std::cout << b << std::endl;
		b.increaseGrade();
		std::cout << b << std::endl;
		b.increaseGrade();
		std::cout << b << std::endl;
	}
	catch ( const std::exception &e )
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Bureaucrat	b1( "Math", 149 );
		std::cout << b1 << std::endl;
		b1.decreaseGrade();
		std::cout << b1 << std::endl;
		b1.decreaseGrade();
		std::cout << b1 << std::endl;
	}
	catch( const std::exception& e )
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Bureaucrat	b2( "Bob", 152 );
		std::cout << b2 << std::endl;
	}
	catch( const std::exception& e )
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Bureaucrat	b3( "Boby", 0 );
		std::cout << b3 << std::endl;
	}
	catch( const std::exception& e )
	{
		std::cerr << e.what() << std::endl;
	}
	return ( 0 );
}