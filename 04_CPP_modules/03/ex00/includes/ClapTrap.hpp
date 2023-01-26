/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 16:18:05 by mmaxime-          #+#    #+#             */
/*   Updated: 2023/01/05 16:18:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
	public:
		ClapTrap();
		ClapTrap( std::string name );
		ClapTrap( ClapTrap const & src );
		~ClapTrap();

		ClapTrap &	operator=( ClapTrap const & rhs );

		void		attack( const std::string & target );
		void		takeDamage( unsigned int amount );
		void		beRepaired( unsigned int amount );

	private:
		std::string		_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;
};

# endif