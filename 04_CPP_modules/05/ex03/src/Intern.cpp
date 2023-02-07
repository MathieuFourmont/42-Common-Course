/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:42:13 by marvin            #+#    #+#             */
/*   Updated: 2023/02/06 12:42:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"

// CONSTRUCTORS AND DESTRUCTOR //

Intern::Intern()
{
	_forms[0] = "shrubbery creation";
	_forms[1] = "robotomy request";
	_forms[2] = "presidential pardon";
	return ;
}

Intern::Intern( Intern const & src )
{
	(void)src;
	return ;
}

Intern::~Intern()
{
	return ;
}

// OVERLOADS //

Intern &	Intern::operator=( Intern const & rhs )
{
	if (this != &rhs)
		(void)rhs;
	return ( *this ) ;
}

// MEMBER FUNCTIONS //

AForm*	Intern::makeForm( std::string name, std::string target )
{
	int i;
	for ( i = 0; i < 3; i++ )
	{
		if ( name.compare( _forms[i] ) == 0 )
			break ;
	}
	switch ( i )
	{
		case 0:
			std::cout << "Intern created a " << name << " form." << std::endl;
			return ( new ShrubberyCreationForm( target ) );
		case 1:
			std::cout << "Intern created a " << name << " form." << std::endl;
			return ( new RobotomyRequestForm( target ) );
		case 2:
			std::cout << "Intern created a " << name << " form." << std::endl;
			return ( new PresidentialPardonForm( target ) );
		default:
			std::cout << "Sorry, this form named: " << name << " doesn't exist." << std::endl;
			break ;
	}
	return ( NULL );
}