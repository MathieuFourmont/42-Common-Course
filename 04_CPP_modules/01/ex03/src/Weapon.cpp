/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <mmaxime-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:15:53 by mmaxime-          #+#    #+#             */
/*   Updated: 2023/01/26 11:15:53 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Weapon.hpp"

Weapon::Weapon( std::string Type ) : _type( Type )
{

}

Weapon::~Weapon()
{

}

void	Weapon::setType( std::string Type )
{
	this->_type = Type;
	return ;
}

std::string const &	Weapon::getType( void ) const
{
	std::string const &	TypeRef = _type;
	return ( TypeRef );
}