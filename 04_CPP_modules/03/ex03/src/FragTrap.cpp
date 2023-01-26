/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <mmaxime-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:33:50 by mmaxime-          #+#    #+#             */
/*   Updated: 2023/01/26 11:33:50 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "A new FragTrap has been created" << std::endl;
	return ;
}

FragTrap::FragTrap( std::string name )
{
	_name = name;
	std::cout << "A new FragTrap " << _name << " has been created" << std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	return ;
}

FragTrap::FragTrap( FragTrap const & src ) : ClapTrap( src )
{
	*this = src;
	std::cout << "New FragTrap " << _name << " has been cloned!" << std::endl;
	return ;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << _name << " has been destroyed..." << std::endl;
	return ;
}

FragTrap & FragTrap::operator=( FragTrap const & rhs )
{
	_name = rhs._name;
	_hitPoints = rhs._hitPoints;
	_energyPoints = rhs._energyPoints;
	_attackDamage = rhs._attackDamage;
	return ( *this );
}

void	FragTrap::attack( const std::string & target )
{
	if ( !_hitPoints || !_energyPoints )
		return ;
	std::cout << _name << " punches " << target << ", causing " << _attackDamage << " damages!" << std::endl;
	_energyPoints--;
	std::cout << "EP left for " << _name << ": " << _energyPoints << std::endl;
	return ;
}

void	FragTrap::highFivesGuys()
{
	if ( _hitPoints > 0 )
		std::cout << _name << " is asking for a high five!" << std::endl;
	return ;
}