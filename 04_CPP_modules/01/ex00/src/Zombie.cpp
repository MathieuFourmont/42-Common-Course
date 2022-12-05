/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 10:46:22 by mmaxime-          #+#    #+#             */
/*   Updated: 2022/10/28 10:46:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie( std::string name ) : _name( name )
{
	std::cout << this->_name << " has been created!" << std::endl;
	return ;
}

Zombie::~Zombie()
{
	std::cout << this->_name << " has been destroyed..." << std::endl;
	return ;
}

void	Zombie::announce( void ) const
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return ;
}