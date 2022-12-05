/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 09:31:09 by mmaxime-          #+#    #+#             */
/*   Updated: 2022/11/03 09:31:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Constructors & destructor

Fixed::Fixed() : _n( 0 )
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed( int const i ) : _n( i )
{
	std::cout << "Int constructor called" << std::endl;
	return ;
}

Fixed::Fixed( float const f ) : _n( f )
{
	std::cout << "Float constructor called" << std::endl;
	return ;
}

Fixed::Fixed( Fixed const & src )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return ;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

// Accessors

int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return ( this->_n );
}

void	Fixed::setRawBits( int const raw )
{
	this->_n = raw;
	return ;
}

// Operator overload

Fixed &	Fixed::operator=( Fixed const & rhs )
{
	std::cout << "Copy assignment operator called" << std::endl;
	if ( this != &rhs )
		this->_n = rhs.getRawBits();
	return ( *this );  
}

// Member functions

float	Fixed::toFloat( void ) const
{

}

int		Fixed::toInt( void ) const
{

}

// Non member function

std::ostream &	operator<<( std::ostream & o, Fixed const & rhs)
{
	o << rhs.getRawBits();
	return (o);
}