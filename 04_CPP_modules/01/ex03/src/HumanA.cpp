/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 16:14:13 by mmaxime-          #+#    #+#             */
/*   Updated: 2022/10/28 16:14:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA( std::string name, Weapon& weapon ) : _name ( name ), _weapon( weapon )
{

}

HumanA::~HumanA()
{

}

void	HumanA::attack() const
{
	std::cout << this->_name << " attacks with his " << this->_weapon.getType() << std::endl;
	return ;
}