/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <mmaxime-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:33:22 by mmaxime-          #+#    #+#             */
/*   Updated: 2023/01/26 11:33:22 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	_name = "";
	ClapTrap::_name = _name + "_clap_name";
	std::cout << "Wow! A DiamondTrap has been created!" << std::endl;
	return ;
}

DiamondTrap::DiamondTrap( std::string name ) : _name( name )
{
	std::cout << "Wow! A DiamondTrap " << this->_name << " has been created!" << std::endl;
	ClapTrap::_name = _name + "_clap_name";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 30;
	return ;
}

DiamondTrap::DiamondTrap( DiamondTrap const & src ) : ClapTrap( src ), ScavTrap( src ), FragTrap( src )
{
	*this = src;
	std::cout << "Wow! A DiamondTrap " << this->_name << " has been cloned!" << std::endl;
	return ;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << this->_name << " has been destroyed!" << std::endl;
	return ;
}

DiamondTrap & DiamondTrap::operator=( DiamondTrap const & rhs )
{
	this->ClapTrap::_name = rhs.ClapTrap::_name;
	this->_name = rhs._name;
	this->_hitPoints = rhs._hitPoints;
	this->_energyPoints = rhs._energyPoints;
	this->_attackDamage = rhs._attackDamage;
	return ( *this );
}

void	DiamondTrap::whoAmI()
{
	if ( _hitPoints > 0 )
		std::cout << "You thought my real name was " << ClapTrap::_name << " while it is " << _name << std::endl;
	return ;
}