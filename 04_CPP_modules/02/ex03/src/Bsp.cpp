/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 11:57:33 by mmaxime-          #+#    #+#             */
/*   Updated: 2023/01/05 11:57:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"
#include "../includes/Point.hpp"

float	getArea( Point a, Point b, Point c)
{
	float x_a = a.getFloatX();
	float y_a = a.getFloatY();
	float x_b = b.getFloatX();
	float y_b = b.getFloatY();
	float x_c = c.getFloatX();
	float y_c = c.getFloatY();
	float area;

	area = ( std::abs( ( x_a * ( y_b - y_c ) + x_b * ( y_c - y_a ) + x_c * ( y_a - y_b ) ) / 2 ) );
	return ( area );
}

bool	bsp( Point const a, Point const b, Point const c, Point const point)
{
	// Le but est de trouver si l'aire du triangle ABC est égale à la somme des aires formées parles triangles :
	//	- ABP
	//	- ACP
	//	- BCP
	// Si différent, alors P n'est pas à l'intérieur de ABC

	float area_ABC = getArea( a, b, c );
	float area_PAB = getArea( point, a, b );
	float area_PBC = getArea( point, b, c );
	float area_PAC = getArea( point, a, c );

	if ( area_ABC == area_PAB + area_PBC + area_PAC )
		return ( true );
	else
		return ( false );
}