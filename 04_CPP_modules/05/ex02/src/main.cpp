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
#include "../includes/AForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"

int	main()
{
	try
	{
		Bureaucrat				agent( "agent", 120 );
		ShrubberyCreationForm	shrubbery( "tree" );

		agent.signForm( shrubbery );
		agent.executeForm( shrubbery );
	}
	catch ( const std::exception &e )
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		Bureaucrat			agent1( "agent1", 46 );
		RobotomyRequestForm	robotomy( "Mathieu" );

		agent1.signForm( robotomy );
		agent1.executeForm( robotomy );
		agent1.increaseGrade();
		agent1.executeForm( robotomy );
		agent1.decreaseGrade();
	}
	catch ( const std::exception &e )
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		Bureaucrat				agent2( "agent2", 1 );
		PresidentialPardonForm	pardon( "Dider" );

		agent2.signForm( pardon );
		agent2.executeForm( pardon );
	}
	catch( const std::exception& e )
	{
		std::cerr << e.what() << std::endl;
	}
	
	return ( 0 );
}