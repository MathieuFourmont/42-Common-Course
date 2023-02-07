/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:45:51 by mmaxime-          #+#    #+#             */
/*   Updated: 2023/02/02 14:45:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource default construcor called" << std::endl;
	for ( int i = 0; i < 4; i++ )
		_inventory[i] = NULL;
	return ;
}

MateriaSource::MateriaSource( MateriaSource const & src )
{
	std::cout << "MateriaSource copy construcor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if ( _inventory[i] != NULL )
			delete( _inventory[i] );
		if ( src._inventoy[i] != NULL )
			_inventory[i] = src._inventory[i]->clone();
	}
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource destructor called" << std::endl;
	for ( int i = 0; i < 4; i++)
	{
		if ( _inventory[i] != NULL )
			delete( _inventory[i] );
	}
	return ;
}

MateriaSource &	MateriaSource::operator=( MateriaSource const & rhs )
{
	if ( this != &rhs)
	{
		for ( int i = 0; i < 4; i++ )
		{
			if ( _inventory[i] != NULL )
				delete( _inventory[i] );	
			_inventory[i] = rhs._inventory[i]->clone();
		}
	}
	return ( *this );
}

void	MateriaSource::learnMateria( AMateria* m )
{
	for ( int i = 0; i < 4; i++ )
	{
		if ( _inventory[i] == NULL )
		{
			_inventory[i] = m;
			return ;
		}
	}
	return ;
}

AMateria*	MateriaSource::createMateria( std::string const & type )
{
	for ( int i = 0; i < 4; i++ )
	{
		if ( _inventory[i] != NULL && type.compare( _inventory[i]->getType() ) == 0 )
			return ( _inventory[i]->clone() );
	}
	return ( 0 );
}