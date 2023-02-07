/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:53:25 by mmaxime-          #+#    #+#             */
/*   Updated: 2023/01/30 11:53:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default contructor called" << std::endl;
	return ;
}

Brain::Brain( Brain const & src )
{
	std::cout << "Brain copy constructor called" << std::endl;
	for ( int i = 0; i < 100; i++ )
		this->_ideas[i] = src._ideas[i];
	return ;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
	return ;
}

Brain &	Brain::operator=( Brain const & rhs )
{
	if ( this != &rhs )
	{
		for ( int i = 0; i < 100; i++ )
			this->_ideas[i] = rhs._ideas[i];
	}
	return ( *this );
}