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

Cat::Cat() : Animal()
{
	std::cout << "Cat default constructor called" << std::endl;
	type = "Cat";
	return ;
}

Cat::Cat( Cat const & src ) : Animal( src )
{
	std::cout << "Cat copy constructor called" << std::endl;
	this->type = src.type;
	return ;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	return ;
}

Cat &	Cat::operator=( Cat const & rhs )
{
	this->type = rhs.type;
	return ( *this );
}

void	Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
	return ;
}