/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:55:18 by mmaxime-          #+#    #+#             */
/*   Updated: 2022/10/28 15:55:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

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