/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:45:54 by marvin            #+#    #+#             */
/*   Updated: 2023/02/02 11:45:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_H
# define ICHARACTER_H

#include <string>
class ICharacter;
#include "AMateria.hpp"

class ICharacter // Une interface est une classe qui n'a que des comportements abstraits -> que des méthodes pures 
// autre particularité : on ne peut pas mettre d'attribut dans les interfaces -> tous les membres d'interface sont implicitement publics et virtuels
// une interface est une manière de définir le comportement pour tout objet héritant de ICharacter, sorte de contrat d'implémentation des classes concrètes
{
	public:
		virtual ~ICharacter() {}

		virtual std::string const &	getName() const = 0;
		virtual void				equip( AMateria* m ) = 0;
		virtual void				unequip( int idx ) = 0;
		virtual void				use( int idx, ICharacter& target) = 0;
};

#endif