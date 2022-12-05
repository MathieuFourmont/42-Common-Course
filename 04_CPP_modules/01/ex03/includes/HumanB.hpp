/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:53:39 by mmaxime-          #+#    #+#             */
/*   Updated: 2022/10/28 15:53:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
# define HUMANB_H

#include <iostream>
#include <string>
#include <iomanip>
#include "Weapon.hpp"

class HumanB
{
	public:
		// Constructeur & Destructeur
		HumanB( std::string name );
		~HumanB();

		// Fonctions membres
		void	setWeapon(Weapon& weapon);
		void	attack() const;

	private:
		std::string	_name;
		Weapon*		_weapon;
};

# endif