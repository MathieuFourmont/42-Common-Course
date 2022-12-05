/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:39:25 by mmaxime-          #+#    #+#             */
/*   Updated: 2022/10/28 15:39:25 by marvin           ###   ########.fr       */
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