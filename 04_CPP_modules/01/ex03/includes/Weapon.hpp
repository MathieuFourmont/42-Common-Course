/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:32:53 by marvin            #+#    #+#             */
/*   Updated: 2022/10/28 15:32:53 by marvin           ###   ########.fr       */
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