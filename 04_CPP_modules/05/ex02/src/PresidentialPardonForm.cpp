/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:57:30 by marvin            #+#    #+#             */
/*   Updated: 2023/02/06 10:57:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PresidentialPardonForm.hpp"

// CONSTRUCTORS AND DESTRUCTOR //

PresidentialPardonForm::PresidentialPardonForm() : AForm()
{
	return ;
}

PresidentialPardonForm::PresidentialPardonForm( std::string target ) : AForm( "PresidentialPardonForm", target, 25, 5 )
{
	return ;
}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const & src ) : AForm( src )
{
	return ;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	return ;
}

// OVERLOADS //

PresidentialPardonForm &	PresidentialPardonForm::operator=( PresidentialPardonForm const & rhs )
{
	if ( this != &rhs )
		(void)rhs;
	return ( *this );
}

// MEMBER FUNCTIONS

void	PresidentialPardonForm::executeSpecForm() const
{
	std::cout << "Zaphod Beeblebrox forgave " << getTarget() << "." << std::endl;
	return ;
}