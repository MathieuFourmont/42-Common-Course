/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 16:18:17 by mmaxime-          #+#    #+#             */
/*   Updated: 2023/01/05 16:18:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "New ClapTrap has been created!" << std::endl;
	return ;
}

ClapTrap::ClapTrap( std::string name ) : _name( name ), _hitPoints( 10 ), _energyPoints( 10 ), _attackDamage( 0 )
{
	std::cout << "New ClapTrap " << _name << " has been created!" << std::endl;
	return ;
}

ClapTrap::ClapTrap( ClapTrap const & src ) : _name( src._name), _hitPoints( src._hitPoints ), _energyPoints( src._energyPoints ), _attackDamage( src._attackDamage )
{
	std::cout << "New ClapTrap " << _name << " has been cloned!" << std::endl;
	return ;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << _name << " has been destroyed..." << std::endl;
	return ;
}

ClapTrap & ClapTrap::operator=( ClapTrap const & rhs )
{
	_name = rhs._name;
	_hitPoints = rhs._hitPoints;
	_energyPoints = rhs._energyPoints;
	_attackDamage = rhs._attackDamage;
	return ( *this );
}

void	ClapTrap::attack( const std::string & target )
{
	if ( !_hitPoints || !_energyPoints )
		return ;
	std::cout << _name << " attacks " << target << ", causing " << _attackDamage << " damages!" << std::endl;
	_energyPoints--;
	std::cout << "EP left: " << _energyPoints << std::endl;
	return ;
}

void	ClapTrap::takeDamage( unsigned int amount )
{
	if ( _hitPoints == 0)
		return ;
	std::cout << _name << " looses " << amount << " HP with this attack..." << std::endl;
	if ( amount > _hitPoints )
		_hitPoints = 0;
	else
		_hitPoints -= amount;
	std::cout << "HP left: " << _hitPoints << std::endl;
	return ;
}

void	ClapTrap::beRepaired( unsigned int amount )
{
	if ( !_hitPoints || !_energyPoints)
		return ;
	std::cout << _name << " repairs himself and recovers " << amount << " HP!" << std::endl;
	_hitPoints += amount;
	_energyPoints--;
	std::cout << "HP are now: " << _hitPoints << std::endl;
	std::cout << "EP left: " << _energyPoints << std::endl;
}
