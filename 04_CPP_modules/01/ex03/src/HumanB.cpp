/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 16:22:02 by mmaxime-          #+#    #+#             */
/*   Updated: 2022/10/28 16:22:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "Weapon.hpp"

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
	std::cout << this->_name << " attacks with his " << this->_weapon->getType() << std::endl;
}