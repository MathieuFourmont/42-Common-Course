/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <mmaxime-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:32:46 by mmaxime-          #+#    #+#             */
/*   Updated: 2023/01/26 11:32:46 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "./ClapTrap.hpp"
#include "./ScavTrap.hpp"
#include "./FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap // ordre de déclaration des super-classes induit celui des appels des constructeurs
{
	public:
		DiamondTrap();
		DiamondTrap( std::string name );
		DiamondTrap( DiamondTrap const & src );
		~DiamondTrap();

		DiamondTrap &	operator=( DiamondTrap const & rhs );

		using			ScavTrap::attack; // ajoute à la liste des déclarations des méthodes/attributs de la sous-classe, une déclaration spéciale indiquant quel(s) membre(s) (attribut/méthode) seront référencé(s) exactement
		void			whoAmI();

	private:
		std::string		_name;
};

#endif