/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:16:41 by mmaxime-          #+#    #+#             */
/*   Updated: 2022/12/26 15:16:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include <iostream>
#include <string>
#include <cmath>
#include "./Fixed.hpp"

class Point
{
public:
	// Constructors & destructor
	Point();
	Point( float const x, float const y );
	Point( Point const & src );
	~Point();

	// Accessor
	float	getFloatX( void ) const;
	float	getFloatY( void ) const;

	// Operator overload
	Point &	operator=( Point const & rhs );

private:
	Fixed const	_x;
	Fixed const	_y;
};

# endif