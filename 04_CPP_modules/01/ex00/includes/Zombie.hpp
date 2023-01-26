/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <mmaxime-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:02:38 by mmaxime-          #+#    #+#             */
/*   Updated: 2023/01/26 11:02:38 by mmaxime-         ###   ########.fr       */
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
		Zombie( std::string name );
		~Zombie();

		// Fonctions membres
		void	announce( void ) const;

	private:
		std::string	_name;
	
};

// Autres fonctions
Zombie*	newZombie( std::string name );
void	randomChump( std::string name );

# endif