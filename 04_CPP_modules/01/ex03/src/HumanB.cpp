/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <mmaxime-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:15:16 by mmaxime-          #+#    #+#             */
/*   Updated: 2023/01/26 11:15:16 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanB.hpp"
#include "../includes/Weapon.hpp"

HumanB::HumanB( std::string name ) : _name( name ), _weapon( NULL )
{

}

HumanB::~HumanB()
{

}

void	HumanB::setWeapon(Weapon& weapon)
{
	this->_weapon = &weapon;
	return ;
}

void	HumanB::attack() const
{
	if ( !_weapon )
		std::cout << this->_name << " attacks with his fists because he doesn't have any weapon" << std::endl;
	else
		std::cout << this->_name << " attacks with his " << this->_weapon->getType() << std::endl;
}
