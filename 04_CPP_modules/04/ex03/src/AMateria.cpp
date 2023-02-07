/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:49:11 by mmaxime-          #+#    #+#             */
/*   Updated: 2023/02/02 14:49:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AMateria.hpp"

AMateria::AMateria()
{
	std::cout << "AMateria default constructor called" << std::endl;
	return ;
}

AMateria::AMateria( std::string const & type ) : _type( type )
{
	std::cout << "AMateria type " << _type << " constructor called" << std::endl;
	return ;
}

AMateria::AMateria( AMateria const & src ) : _type( src._type )
{
	std::cout << "AMateria copy constructor called" << std::endl;
	return ;
}

AMateria::~AMateria()
{
	std::cout << "AMateria destructor called" << std::endl;
	return ;
}

AMateria &	AMateria::operator=( AMateria const & rhs )
{
	if ( this != &rhs )
		this->_type = rhs._type;
	return ( *this );
}

std::string const &	AMateria::getType() const
{
	return ( _type );
}

// AMateria*	AMateria::clone() // méthode pure donc pas besoin de la définir dans le .cpp
// {

// }

void	AMateria::use( ICharacter& target )
{
	( void )target;
	return ;
}