/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <mmaxime-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:27:20 by mmaxime-          #+#    #+#             */
/*   Updated: 2023/01/26 11:27:20 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

// Constructors & destructor

Fixed::Fixed() : _n( 0 )
{
	return ;
}

Fixed::Fixed( int const i ) : _n( i )
{
	this->_n = this->_n << this->_binaryPoint;
	return ;
}

Fixed::Fixed( float const f ) : _n( f )
{
	this->_n = round( f * ( 1 << this->_binaryPoint ) ); // -> * 256
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

// Accessors

int	Fixed::getRawBits( void ) const
{
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
	if ( this != &rhs )
		this->_n = rhs.getRawBits();
	return ( *this );  
}

Fixed	Fixed::operator+( Fixed const & rhs ) const
{
	//std::cout << "Addition operator called with " << this->_n;
	//std::cout << " and " << rhs.getRawBits() << std::endl;

	return ( Fixed( this->toFloat() + rhs.toFloat() ) );
}

Fixed	Fixed::operator-( Fixed const & rhs ) const
{
	//std::cout << "Substraction operator called with " << this->_n;
	//std::cout << " and " << rhs.getRawBits() << std::endl;

	return ( Fixed( this->toFloat() - rhs.toFloat() ) );
}

Fixed	Fixed::operator*( Fixed const & rhs ) const
{
	//std::cout << "Multiplication operator called with " << this->_n;
	//std::cout << " and " << rhs.getRawBits() << std::endl;

	return ( Fixed( this->toFloat() * rhs.toFloat() ) );
}

Fixed	Fixed::operator/( Fixed const & rhs ) const
{
	//std::cout << "Division operator called with " << this->_n;
	//std::cout << " and " << rhs.getRawBits() << std::endl;

	return ( Fixed( this->toFloat() / rhs.toFloat() ) );
}

bool	Fixed::operator>( Fixed const & rhs ) const
{
	//std::cout << "Comparison > operator called" << std::endl;
	if ( this->_n > rhs.getRawBits() )
		return ( true );
	else
		return ( false );
}

bool	Fixed::operator<( Fixed const & rhs ) const
{
	if ( this->_n < rhs.getRawBits() )
		return ( true );
	else
		return ( false );
}

bool	Fixed::operator>=( Fixed const & rhs ) const
{
	if ( this->_n >= rhs.getRawBits() )
		return ( true );
	else
		return ( false );
}

bool	Fixed::operator<=( Fixed const & rhs ) const
{
	if ( this->_n <= rhs.getRawBits() )
		return ( true );
	else
		return ( false );
}

bool	Fixed::operator==( Fixed const & rhs ) const
{
	if ( this->_n == rhs.getRawBits() )
		return ( true );
	else
		return ( false );
}

bool	Fixed::operator!=( Fixed const & rhs ) const
{
	if ( this->_n != rhs.getRawBits() )
		return ( true );
	else
		return ( false );
}

Fixed	Fixed::operator++( int ) // post-incrémentation
{
	Fixed	tmp;

	tmp = *this;
	this->_n += 1;
	return ( tmp );
}
Fixed & Fixed::operator++() // pré-incrémentation
{
	this->_n += 1;
	return ( *this );
}
Fixed	Fixed::operator--( int )
{
	Fixed	tmp;

	tmp = *this;
	this->_n -= 1;
	return ( tmp );
}
Fixed & Fixed::operator--()
{
	this->_n -= 1;
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

Fixed &	Fixed::min( Fixed & x, Fixed & y )
{
	if ( x._n < y._n )
		return ( x );
	else
		return ( y );
}

Fixed const &	Fixed::min( Fixed const & x, Fixed const & y )
{
	if ( x._n < y._n )
		return ( x );
	else
		return ( y );
}

Fixed &	Fixed::max( Fixed & x, Fixed & y )
{
	if ( x._n > y._n )
		return ( x );
	else
		return ( y );
}

Fixed const &	Fixed::max( Fixed const & x, Fixed const & y )
{
	if ( x._n > y._n )
		return ( x );
	else
		return ( y );
}

// Non member function

std::ostream &	operator<<( std::ostream & o, Fixed const & rhs)
{
	o << rhs.toFloat();
	return (o);
}