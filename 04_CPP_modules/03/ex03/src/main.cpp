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