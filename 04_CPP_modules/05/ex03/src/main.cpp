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
#include "../includes/Intern.hpp"

int	main()
{
	Bureaucrat	agent( "Mathieu", 1 );
	Intern		someRandomIntern;
	AForm*		form;

	form = someRandomIntern.makeForm( "robotomy request", "Bender" );
	agent.signForm( *form );
	agent.executeForm( *form );
	delete ( form );
	std::cout << std::endl;
	form = someRandomIntern.makeForm( "contract", "Agreement" );
	delete ( form );

	return ( 0 );
}