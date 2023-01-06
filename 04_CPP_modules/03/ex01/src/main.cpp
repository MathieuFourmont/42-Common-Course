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

#include "../includes/ScavTrap.hpp"

int	main()
{
	ClapTrap	Homer( "Homer" );
	ScavTrap	Hercules( "Hercules" );
	ScavTrap	clone( Hercules );

	// Test 0 : everything's ok
	std::cout << std::endl << "Test 0" << std::endl;
	Homer.takeDamage( 5 );
	Homer.beRepaired( 2 );
	Homer.attack( "Lernaean Hydra");
	clone.attack( "Lernaean Hydra");
	clone.takeDamage( 10 );
	clone.beRepaired( 2 );
	clone.guardGate();
	std::cout << std::endl;
	
	// Test 1 : Hercules takes big damages and dies
	std::cout << "Test 1" << std::endl;
	clone.takeDamage( 100 );
	clone.attack( "Nemean lion" ); // should do nothing
	clone.beRepaired( 10 ); // should do nothing
	clone.takeDamage( 50 ); // should do nothing
	std::cout << std::endl;

	// Test 2 : Hercules attacks/repairs so many times, he lost all his EP
	std::cout << "Test 2";
	for (int i = 0; i < 26; i++)
	{
		std::cout << std::endl << "i = " << i << std::endl;
		Hercules.attack( "Geryon");
		Hercules.takeDamage( 1 );
		Hercules.beRepaired ( 3 );
	}	
	return ( 0 );
}