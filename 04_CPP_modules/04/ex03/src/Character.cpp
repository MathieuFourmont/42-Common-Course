/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:15:54 by mmaxime-          #+#    #+#             */
/*   Updated: 2023/02/02 16:15:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Character.hpp"

Character::Character()
{
	std::cout << "Character default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	return ;
}

Character::Character( std::string name ) : _name( name )
{
	std::cout << "Character " << _name << " constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	return ;
}

Character::Character( Character const & src ) : _name( src._name )
{
	std::cout << "Character copy constructor called" << std::endl;
	for ( int i = 0; i < 4; i++ )
	{
		if ( _inventory[i] != NULL )
			delete( _inventory[i] );
		if ( src._inventory[i] != NULL )
			_inventory[i] = src._inventory[i]->clone();
	}
	return ;
}

Character::~Character()
{
	std::cout << "Character destructor called" << std::endl;
	for ( int i = 0; i < 4; i++)
	{
		if ( _inventory[i] != NULL )
			delete( _inventory[i] );
	}
	return ;
}

Character &	Character::operator=( Character const & rhs )
{
	if ( this != &rhs)
	{
		_name = rhs._name;
		for ( int i = 0; i < 4; i++ )
		{
			if ( _inventory[i] != NULL )
				delete( _inventory[i] );	
			_inventory[i] = rhs._inventory[i]->clone();
		}
	}
	return ( *this );
}

std::string const &	Character::getName() const
{
	return ( _name );
}

void	Character::equip( AMateria* m )
{
	for ( int i = 0; i < 4; i++ )
	{
		if ( _inventory[i] == NULL )
		{
			_inventory[i] = m;
			return ;
		}
	}
	delete( m ); // cas où inventaire est plein
	return ;
}

void	Character::unequip( int idx )
{
	if ( _inventory[idx] != NULL )
		_inventory[idx] = NULL;
	return ;
}

void	Character::use( int idx, ICharacter& target )
{
	if ( _inventory[idx] != NULL )
		_inventory[idx]->use( target );
	return ;
}