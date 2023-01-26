/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:30:22 by marvin            #+#    #+#             */
/*   Updated: 2023/01/25 18:30:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal default constructor called" << std::endl;
	return ;
}

Animal::Animal( Animal const & src )
{
	std::cout << "Animal copy constructor called" << std::endl;
	this->type = src.type;
	return ;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
	return ;
}

Animal &	Animal::operator=( Animal const & rhs )
{
	this->type = rhs.type;
	return ( *this );
}

std::string const	Animal::getType() const
{
	return ( type );
}

void	Animal::makeSound() const
{
	std::cout << "I'm an undefined animal" << std::endl;
	return ;
}