/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <mmaxime-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:28:44 by mmaxime-          #+#    #+#             */
/*   Updated: 2023/01/26 11:28:44 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"
#include "../includes/Point.hpp"

bool	bsp( Point const a, Point const b, Point const c, Point const point);

int	main()
{
	Point	a( 2.0f, 2.0f );
	Point	b( 5.0f, 3.0f );
	Point	c( 3.0f, 5.0f );
	Point	p( -3.0f, 3.0f );

	std::cout << "Is point P inside of ABC? " << bsp( a, b, c, p ) << std::endl;
	return 0;
}