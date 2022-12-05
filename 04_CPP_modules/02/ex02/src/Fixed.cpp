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

Fixed::Fixed() : _n( 0 )
{
	return ;
}

Fixed::Fixed( int const n ) : _n( n )
{
	return ;
}

Fixed::Fixed( Fixed const & src )
{
	*this = src;
	return ;
}

Fixed::~Fixed()
{
	return ;
}

int	Fixed::getValue( void ) const
{
	return ( this->_n );
}

Fixed &	Fixed::operator=( Fixed const & rhs )
{
	std::cout << "Assignation operator called from " << this->_n;
	std::cout << " to " << rhs.getValue() << std::endl;

	this->_n = rhs.getValue();

	return ( *this );  
}

Fixed	Fixed::operator+( Fixed const & rhs ) const
{
	std::cout << "Addition operator called with " << this->_n;
	std::cout << " and " << rhs.getValue() << std::endl;

	return ( Fixed( this->_n + rhs.getValue() ) );
}

Fixed	Fixed::operator-( Fixed const & rhs ) const
{
	std::cout << "Substraction operator called with " << this->_n;
	std::cout << " and " << rhs.getValue() << std::endl;

	return ( Fixed( this->_n - rhs.getValue() ) );
}

Fixed	Fixed::operator*( Fixed const & rhs ) const
{
	std::cout << "Multiplication operator called with " << this->_n;
	std::cout << " and " << rhs.getValue() << std::endl;

	return ( Fixed( this->_n * rhs.getValue() ) );
}

Fixed	Fixed::operator/( Fixed const & rhs ) const
{
	std::cout << "Division operator called with " << this->_n;
	std::cout << " and " << rhs.getValue() << std::endl;

	return ( Fixed( this->_n / rhs.getValue() ) );
}

std::ostream &	operator<<( std::ostream & o, Fixed const & rhs)
{
	o << rhs.getValue();
	return (o);
}