/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <mmaxime-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:28:30 by mmaxime-          #+#    #+#             */
/*   Updated: 2023/02/14 14:34:22 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/easyfind.hpp"

int main()
{
	std::cout << "Test 1 -> int" << std::endl;
	{
		std::vector<int>	vect1;
		int					toFind;

		for ( int i = 0; i < 5; ++i )
			vect1.push_back( i );
		toFind = 4;
		try
		{
			easyfind( vect1, toFind );
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << " " << toFind << " not found in container." << std::endl;;
		}
	}
		std::cout << std::endl << "Test 2 -> char" << std::endl;
	{
		std::vector<int>	vect2;
		char				toFind;

		for ( char c = 'a'; c < 'e'; ++c )
			vect2.push_back( c );
		toFind = 'g';
		try
		{
			easyfind( vect2, toFind );
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << " " << toFind << " not found in container." << std::endl;;
		}
	}
		std::cout << std::endl << "Test 3 -> float" << std::endl;
	{
		std::vector<int>	vect3;
		float				toFind;

		for ( float f = 53; f < 72; ++f )
			vect3.push_back( f );
		toFind = 53.5f;
		try
		{
			easyfind( vect3, toFind );
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << " " << toFind << " not found in container." << std::endl;;
		}
	}

	return ( 0 );
}