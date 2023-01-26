/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <mmaxime-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:14:17 by mmaxime-          #+#    #+#             */
/*   Updated: 2023/01/26 11:14:17 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
# define HUMANA_H

#include <iostream>
#include <string>
#include <iomanip>
#include "Weapon.hpp"

class HumanA
{
	public:
		// Constructeur & Destructeur
		HumanA( std::string name, Weapon& weapon );
		~HumanA();

		// Fonctions membres
		void	attack() const;

	private:
		std::string	_name;
		Weapon&		_weapon;
};

# endif