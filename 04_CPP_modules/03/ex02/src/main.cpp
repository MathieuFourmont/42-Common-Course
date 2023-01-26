/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <mmaxime-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:31:53 by mmaxime-          #+#    #+#             */
/*   Updated: 2023/01/26 11:31:53 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"
#include "../includes/FragTrap.hpp"

int	main()
{
	ClapTrap	clap( "Homer" );
	ScavTrap	scrav( "Hercules" );
	FragTrap	frag( "Achilles" );

	// Test 0 : everything's ok
	std::cout << std::endl;
	clap.takeDamage( 5 );
	clap.beRepaired( 2 );
	clap.attack( "Lernaean Hydra");
	scrav.attack( "Lernaean Hydra");
	scrav.takeDamage( 10 );
	scrav.beRepaired( 2 );
	scrav.guardGate();
	frag.attack( "Lernaean Hydra");
	frag.takeDamage( 10 );
	frag.beRepaired( 2 );
	frag.highFivesGuys();
	std::cout << std::endl;
	
	// Test 1 : Hercules takes big damages and dies
	// std::cout << "Test 1" << std::endl;
	// clone.takeDamage( 100 );
	// clone.attack( "Nemean lion" ); // should do nothing
	// clone.beRepaired( 10 ); // should do nothing
	// clone.takeDamage( 50 ); // should do nothing
	// std::cout << std::endl;

	// // Test 2 : Hercules attacks/repairs so many times, he lost all his EP
	// std::cout << "Test 2";
	// for (int i = 0; i < 26; i++)
	// {
	// 	std::cout << std::endl << "i = " << i << std::endl;
	// 	Hercules.attack( "Geryon");
	// 	Hercules.takeDamage( 1 );
	// 	Hercules.beRepaired ( 3 );
	// }	
	return ( 0 );
}