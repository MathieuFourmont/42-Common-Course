/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <mmaxime-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 12:25:47 by mmaxime-          #+#    #+#             */
/*   Updated: 2023/01/26 12:25:49 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	std::cout << "WrongCat default constructor called" << std::endl;
	type = "WrongCat";
	return ;
}

WrongCat::WrongCat( WrongCat const & src ) : WrongAnimal( src )
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	this->type = src.type;
	return ;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
	return ;
}

WrongCat &	WrongCat::operator=( WrongCat const & rhs )
{
	if ( this != &rhs )
		this->type = rhs.type;
	return ( *this );
}

void	WrongCat::makeSound() const
{
	std::cout << "Wrong meow" << std::endl;
	return ;
}