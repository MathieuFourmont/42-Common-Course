/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:28:54 by marvin            #+#    #+#             */
/*   Updated: 2023/01/25 19:28:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Dog default constructor called" << std::endl;
	type = "Dog";
	return ;
}

Dog::Dog( Dog const & src ) : Animal( src )
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->type = src.type;
	return ;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	return ;
}

Dog &	Dog::operator=( Dog const & rhs )
{
	this->type = rhs.type;
	return ( *this );
}

void	Dog::makeSound() const
{
	std::cout << "Woof" << std::endl;
	return ;
}