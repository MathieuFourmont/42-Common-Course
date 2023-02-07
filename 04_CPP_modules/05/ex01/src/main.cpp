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
#include "../includes/Form.hpp"

int	main()
{
	try
	{
		Bureaucrat	b( "Mathieu", 11 );
		Bureaucrat	b1( "Math", 1);
		Form		f("Deal", 10, 10);

		std::cout << b << std::endl;
		std::cout << b1 << std::endl;
		std::cout << f << std::endl;

		std::cout << std::endl;

		b.signForm( f );
		std::cout << f << std::endl;
		b1.signForm( f );
		std::cout << f << std::endl;
	}
	catch ( const std::exception &e )
	{
		std::cerr << e.what() << std::endl;
	}
	return ( 0 );
}