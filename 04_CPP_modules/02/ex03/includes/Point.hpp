/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <mmaxime-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:28:01 by mmaxime-          #+#    #+#             */
/*   Updated: 2023/01/26 11:28:01 by mmaxime-         ###   ########.fr       */
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