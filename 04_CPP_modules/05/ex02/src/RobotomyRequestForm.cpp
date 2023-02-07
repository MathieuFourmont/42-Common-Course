/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:14:24 by marvin            #+#    #+#             */
/*   Updated: 2023/02/06 10:14:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RobotomyRequestForm.hpp"
#include <stdlib.h>

// CONSTRUCTORS AND DESTRUCTOR //

RobotomyRequestForm::RobotomyRequestForm() : AForm()
{
	return ;
}

RobotomyRequestForm::RobotomyRequestForm( std::string target ) : AForm( "RobotomyRequestForm", target, 72, 45 )
{
	return ;
}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const & src ) : AForm( src )
{
	return ;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	return ;
}

// OVERLOADS //

RobotomyRequestForm &	RobotomyRequestForm::operator=( RobotomyRequestForm const & rhs )
{
	if ( this != &rhs )
		(void)rhs;
	return ( *this );
}

// MEMBER FUNCTIONS //

void	RobotomyRequestForm::executeSpecForm() const
{
	std::cout << "* Sounds of drilling are heard *" << std::endl;
	srand( time(NULL) );
	if ( rand() % 2 == 0 )
		std::cout << getTarget() << " has been robotomized!" << std::endl;
	else
		std::cout << "Robotomization of " << getTarget() << " failed..." << std::endl;
	return ;
}