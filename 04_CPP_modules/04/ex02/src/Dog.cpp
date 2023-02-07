/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <mmaxime-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:01:54 by mmaxime-          #+#    #+#             */
/*   Updated: 2023/01/26 11:01:54 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

Dog::Dog() : AAnimal()
{
	std::cout << "Dog default constructor called" << std::endl;
	type = "Dog";
	_brain = new Brain();
	return ;
}

Dog::Dog( Dog const & src ) : AAnimal( src )
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->type = src.type;
	_brain = new Brain ( *src._brain ); // proto de copie = &src -> il faut donc envoyer l'objet lui même et non son adresse
	return ;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete ( _brain );
	return ;
}

Dog &	Dog::operator=( Dog const & rhs )
{
	if ( this != &rhs )
	{
		this->type = rhs.type;
		delete ( _brain ); // penser à supprimer "l'ancien" _brain
		_brain = new Brain( *rhs._brain );
	}
	return ( *this );
}

void	Dog::makeSound() const
{
	std::cout << "Woof" << std::endl;
	return ;
}