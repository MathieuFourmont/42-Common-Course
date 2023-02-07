/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <mmaxime-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:00:20 by mmaxime-          #+#    #+#             */
/*   Updated: 2023/01/26 11:00:20 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AAnimal.hpp"

AAnimal::AAnimal()
{
	std::cout << "AAnimal default constructor called" << std::endl;
	return ;
}

AAnimal::AAnimal( AAnimal const & src )
{
	std::cout << "AAnimal copy constructor called" << std::endl;
	this->type = src.type;
	return ;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor called" << std::endl;
	return ;
}

AAnimal &	AAnimal::operator=( AAnimal const & rhs )
{
	if ( this != &rhs )
		this->type = rhs.type;
	return ( *this );
}

std::string const	AAnimal::getType() const
{
	return ( type );
}

void	AAnimal::makeSound() const
{
	std::cout << "I'm an undefined Aanimal" << std::endl;
	return ;
}