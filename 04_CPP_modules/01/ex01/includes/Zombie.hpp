/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 10:40:14 by mmaxime-          #+#    #+#             */
/*   Updated: 2022/10/28 10:40:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <iostream>
#include <string>
#include <iomanip>

class Zombie
{
	public:
		// Constructeur et destructeur
		Zombie();
		~Zombie();

		// Fonctions membres
		void	SetName( std::string name );
		void	announce( void ) const;

	private:
		std::string	_name;
	
};

// Autres fonctions
Zombie*	zombieHorde(int N, std::string name );

# endif