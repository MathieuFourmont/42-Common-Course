/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <mmaxime-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:00:38 by mmaxime-          #+#    #+#             */
/*   Updated: 2023/01/26 11:00:38 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
# define ANIMAL_H

#include <iostream>
#include <string>

class Animal
{
	public:
		Animal();
		Animal( Animal const & src );
		virtual ~Animal(); // le destructeur doit être virtual si au moins une méthode est déclarée comme virtual

		Animal &			operator=( Animal const & rhs );

		std::string const	getType() const;
		virtual void		makeSound() const;

	protected:
		std::string			type;
};

#endif