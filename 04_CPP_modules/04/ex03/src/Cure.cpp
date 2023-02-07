/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:50:06 by mmaxime-          #+#    #+#             */
/*   Updated: 2023/02/02 11:50:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cure.hpp"

Cure::Cure() : AMateria( "cure" )
{
	std::cout << "Cure default constructor called" << std::endl;
	return ;
}

Cure::Cure( Cure const & src ) : AMateria( src )
{
	std::cout << "Cure copy constructor called" << std::endl;
	return ;
}

Cure::~Cure()
{
	std::cout << "Cure destructor called" << std::endl;
	return ;
}

Cure &	Cure::operator=( Cure const & rhs )
{
	if ( this != &rhs )
		this->_type = rhs._type;
	return ( *this );
}

AMateria*	Cure::clone() const
{
	return ( new Cure( *this ) );
}

void	Cure::use( ICharacter& target )
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
	return ;
}