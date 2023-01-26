/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <mmaxime-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:14:25 by mmaxime-          #+#    #+#             */
/*   Updated: 2023/01/26 11:14:25 by mmaxime-         ###   ########.fr       */
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