/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 09:31:35 by mmaxime-          #+#    #+#             */
/*   Updated: 2022/11/03 09:31:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main()
{
	Fixed	x( 4 );
	Fixed	y( 3 );
	Fixed	z( 0 );

	std::cout << "Value of x: " << x << std::endl;
	std::cout << "Value of y: " << y << std::endl;
	y = Fixed( 5 );
	std::cout << "Value of y: " << y << std::endl;

	std::cout << "Value of z: " << z << std::endl;
	z = y / x;
	std::cout << "Value of z: " << z << std::endl;

	return (0);
}