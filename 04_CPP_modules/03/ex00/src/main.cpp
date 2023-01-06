/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:05:24 by mmaxime-          #+#    #+#             */
/*   Updated: 2023/01/05 18:05:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

int	main()
{
	ClapTrap	hercules( "Hercules" );
	ClapTrap	clone( hercules );

	// Test 1 : Hercules takes big damages and dies
	std::cout << "Test 1" << std::endl;
	clone.takeDamage( 50 );
	clone.attack( "Nemean lion" ); // should do nothing
	clone.beRepaired( 10 ); // should do nothing
	clone.takeDamage( 50 ); // should do nothing
	std::cout << std::endl;

	// Test 2 : Hercules attacks/repairs so many times, he lost all his EP
	std::cout << std::endl << "Test 2";
	for (int i = 0; i < 10; i++)
	{
		std::cout << std::endl << "i = " << i << std::endl;
		hercules.attack( "Geryon");
		hercules.takeDamage( 1 );
		hercules.beRepaired ( 3 );
	}	
	return ( 0 );
}