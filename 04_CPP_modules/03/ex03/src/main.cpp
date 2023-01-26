/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <mmaxime-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:33:59 by mmaxime-          #+#    #+#             */
/*   Updated: 2023/01/26 11:33:59 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/DiamondTrap.hpp"

int	main()
{
	DiamondTrap	diamond( "Typhon" );

	std::cout << std::endl;
	diamond.attack( "Homer" );
	diamond.takeDamage( 20 );
	diamond.beRepaired( 4 );
	diamond.guardGate();
	diamond.highFivesGuys();
	diamond.whoAmI();
	std::cout << std::endl;
	return ( 0 );
}