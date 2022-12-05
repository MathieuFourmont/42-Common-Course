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