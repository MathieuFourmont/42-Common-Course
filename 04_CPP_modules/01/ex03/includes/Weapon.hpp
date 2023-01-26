/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <mmaxime-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:14:34 by mmaxime-          #+#    #+#             */
/*   Updated: 2023/01/26 11:14:34 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H

#include <iostream>
#include <string>
#include <iomanip>

class Weapon
{
	public:
		// Constructeur & Destructeur
		Weapon( std::string Type );
		~Weapon();

		// Fonct° membres
		void				setType( std::string Type );
		std::string const &	getType( void ) const;

	private:
		std::string	_type;

};

# endif