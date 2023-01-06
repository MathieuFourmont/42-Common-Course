/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 10:45:07 by mmaxime-          #+#    #+#             */
/*   Updated: 2023/01/06 10:45:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "./ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap // avec virtual, l'appel explicite au constructeur de ClapTrap est ignoré
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