/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:21:26 by mmaxime-          #+#    #+#             */
/*   Updated: 2022/12/26 15:21:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"
#include "../includes/Point.hpp"

// Constructors & destructor

Point::Point() : _x( 0 ), _y( 0 )
{
	return ;
}

Point::Point( float const x, float const y) : _x( x ), _y( y )
{
	return ;
}

Point::Point( Point const & src ) : _x( src._x ), _y( src._y )
{
	return ;
}

Point::~Point()
{
	return ;
}

// Operator overload

Point &	Point::operator=( Point const & rhs )
{
	(void)rhs;
	return ( *this );
}

float	Point::getFloatX( void ) const
{
	return ( this->_x.toFloat() );
}

float	Point::getFloatY( void ) const
{
	return ( this->_y.toFloat() );
}