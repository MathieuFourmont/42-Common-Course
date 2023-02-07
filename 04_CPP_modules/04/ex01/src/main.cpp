/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <mmaxime-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:02:05 by mmaxime-          #+#    #+#             */
/*   Updated: 2023/01/26 11:02:05 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"

int	main()
{
	Animal*	tab[50];
	
	for( int i = 0; i < 25; i++)
		tab[i] = new Dog();
	for( int i = 25; i < 50; i++)
		tab[i] = new Cat();
	for ( int i = 0; i < 50; i++)
		delete( tab[i] );

	return ( 0 );
}