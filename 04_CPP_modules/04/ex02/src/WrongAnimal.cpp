/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <mmaxime-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 12:24:50 by mmaxime-          #+#    #+#             */
/*   Updated: 2023/01/26 12:24:50 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
	return ;
}

WrongAnimal::WrongAnimal( WrongAnimal const & src )
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	this->type = src.type;
	return ;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
	return ;
}

WrongAnimal &	WrongAnimal::operator=( WrongAnimal const & rhs )
{
	if ( this != &rhs )
		this->type = rhs.type;
	return ( *this );
}

std::string const	WrongAnimal::getType() const
{
	return ( type );
}

void	WrongAnimal::makeSound() const
{
	std::cout << "I'm an undefined wrong animal" << std::endl;
	return ;
}