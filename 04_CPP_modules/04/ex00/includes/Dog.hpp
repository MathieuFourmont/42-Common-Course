/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <mmaxime-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:01:10 by mmaxime-          #+#    #+#             */
/*   Updated: 2023/01/26 11:01:10 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
# define DOG_H

#include <iostream>
#include <string>
#include "Animal.hpp"

class Dog : public Animal
{
	public:
		Dog();
		Dog( Dog const & src );
		~Dog();

		Dog &	operator=( Dog const & rhs );

		void	makeSound() const;
};

#endif