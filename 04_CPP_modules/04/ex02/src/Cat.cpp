/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <mmaxime-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:01:43 by mmaxime-          #+#    #+#             */
/*   Updated: 2023/01/26 11:01:43 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

Cat::Cat() : AAnimal()
{
	std::cout << "Cat default constructor called" << std::endl;
	type = "Cat";
	_brain = new Brain();
	return ;
}

Cat::Cat( Cat const & src ) : AAnimal( src )
{
	std::cout << "Cat copy constructor called" << std::endl;
	this->type = src.type;
	_brain = new Brain( *src._brain ); // proto de copie = &src -> il faut donc envoyer l'objet lui même et non son adresse
	return ;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete( _brain );
	return ;
}

Cat &	Cat::operator=( Cat const & rhs )
{
	if ( this != &rhs )
	{
		this->type = rhs.type;
		delete( _brain ); // penser à supprimer "l'ancien" _brain
		_brain = new Brain ( *rhs._brain );
	}
	return ( *this );
}

void	Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
	return ;
}