/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <mmaxime-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:04:16 by mmaxime-          #+#    #+#             */
/*   Updated: 2023/01/26 11:04:16 by mmaxime-         ###   ########.fr       */
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