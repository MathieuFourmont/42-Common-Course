/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:49:35 by mmaxime-          #+#    #+#             */
/*   Updated: 2023/02/02 11:49:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Ice.hpp"

Ice::Ice() : AMateria( "ice" )
{
	std::cout << "Ice default constructor called" << std::endl;
	return ;
}

Ice::Ice( Ice const & src ) : AMateria( src )
{
	std::cout << "Ice copy constructor called" << std::endl;
	return ;
}

Ice::~Ice()
{
	std::cout << "Ice destructor called" << std::endl;
	return ;
}

Ice &	Ice::operator=( Ice const & rhs )
{
	if ( this != &rhs )
		this->_type = rhs._type;
	return ( *this );
}

AMateria*	Ice::clone() const
{
	return ( new Ice( *this ) );
}

void	Ice::use( ICharacter& target )
{
	std::cout << "*shoots an ice bolt at " << target.getName() << " *" << std::endl;
	return ;
}