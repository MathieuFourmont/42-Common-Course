/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <mmaxime-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:08:59 by mmaxime-          #+#    #+#             */
/*   Updated: 2023/01/26 11:08:59 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "A zombie has been created!" << std::endl;
	return ;
}

Zombie::~Zombie()
{
	std::cout << this->_name << " has been destroyed..." << std::endl;
	return ;
}

void	Zombie::SetName( std::string name)
{
	this->_name = name;
	return ;
}

void	Zombie::announce( void ) const
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return ;
}