/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <mmaxime-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:34:08 by mmaxime-          #+#    #+#             */
/*   Updated: 2023/01/26 11:34:08 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "A new ScavTrap has been created" << std::endl;
	return ;
}

ScavTrap::ScavTrap( std::string name )
{
	_name = name;
	std::cout << "A new ScavTrap " << _name << " has been created" << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	return ;
}

ScavTrap::ScavTrap( ScavTrap const & src ) : ClapTrap( src )
{
	*this = src;
	std::cout << "New ScavTrap " << _name << " has been cloned!" << std::endl;
	return ;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << _name << " has been destroyed..." << std::endl;
	return ;
}

ScavTrap & ScavTrap::operator=( ScavTrap const & rhs )
{
	_name = rhs._name;
	_hitPoints = rhs._hitPoints;
	_energyPoints = rhs._energyPoints;
	_attackDamage = rhs._attackDamage;
	return ( *this );
}

void	ScavTrap::attack( const std::string & target )
{
	if ( !_hitPoints || !_energyPoints )
		return ;
	std::cout << _name << " hits " << target << ", causing " << _attackDamage << " damages!" << std::endl;
	_energyPoints--;
	std::cout << "EP left for " << _name << ": " << _energyPoints << std::endl;
	return ;
}

void	ScavTrap::guardGate()
{
	if ( _hitPoints > 0 )
		std::cout << _name << " has entered guarding Gate mode" << std::endl;
	return ;
}