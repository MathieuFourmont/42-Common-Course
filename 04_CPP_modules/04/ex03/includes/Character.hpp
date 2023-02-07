/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:23:25 by mmaxime-          #+#    #+#             */
/*   Updated: 2023/02/02 15:23:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>
#include "ICharacter.hpp"

class Character : public ICharacter
{
	public:
		Character();
		Character( std::string name );
		Character( Character const & src );
		~Character();

		Character &			operator=( Character const & rhs );

		std::string const &	getName() const;
		void				equip( AMateria* m );
		void				unequip( int idx );
		void				use( int idx, ICharacter& target);

	private:
		std::string			_name;
		AMateria*			_inventory[4];
};

#endif