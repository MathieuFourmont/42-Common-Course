/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:18:12 by marvin            #+#    #+#             */
/*   Updated: 2023/01/25 18:18:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
	public:
		Animal();
		Animal( Animal const & src );
		virtual	~Animal();

		Animal &			operator=( Animal const & rhs );

		std::string const	getType() const;
		virtual void		makeSound() const;

	protected:
		std::string			type;
};

#endif