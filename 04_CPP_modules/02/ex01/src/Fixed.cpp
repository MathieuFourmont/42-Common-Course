/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <mmaxime-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 18:06:49 by mmaxime-          #+#    #+#             */
/*   Updated: 2022/12/05 18:06:49 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

// Constructors & destructor

Fixed::Fixed() : _n( 0 )
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed( int const i ) : _n( i )
{
	std::cout << "Int constructor called" << std::endl;
	this->_n = this->_n << this->_binaryPoint; // décale de 8 bits vers la gauche -> pour 10, on obtient 2056
	return ;
}

Fixed::Fixed( float const f ) : _n( f )
{
	std::cout << "Float constructor called" << std::endl;
	this->_n = round( f * ( 1 << this->_binaryPoint ) ); // -> * 256
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
	std::cout << "Copy assignment operator called" << std::endl;
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
	//std::cout << "Copy assignment operator called" << std::endl;
	if ( this != &rhs )
		this->_n = rhs.getRawBits();
	return ( *this );  
}

// Member functions

float	Fixed::toFloat( void ) const
{
	return ( ( float )this->_n / ( 1 << this->_binaryPoint )); // -> / 256
}

int		Fixed::toInt( void ) const
{
	return ( this->_n  >> this->_binaryPoint );
}

// Non member function

std::ostream &	operator<<( std::ostream & o, Fixed const & rhs)
{
	o << rhs.toFloat();
	return (o);
}