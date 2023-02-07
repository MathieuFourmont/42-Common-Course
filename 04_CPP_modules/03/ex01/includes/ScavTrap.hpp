/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <mmaxime-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:30:17 by mmaxime-          #+#    #+#             */
/*   Updated: 2023/01/26 11:30:17 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
# define SCAVTRAP_H

#include "./ClapTrap.hpp"

class ScavTrap : public ClapTrap // ScavTrap hérite de la classe ClapTrap, ScavTrap est alors appelée "spécialisation" de ClapTrap
{
	public:
		ScavTrap();
		ScavTrap( std::string name );
		ScavTrap( ScavTrap const & src );
		~ScavTrap();

		ScavTrap &	operator=( ScavTrap const & rhs );

		void		attack( const std::string & target );
		void		guardGate(); // ne concerne que ScavTrap

};

# endif