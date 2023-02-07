/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:38:32 by mmaxime-          #+#    #+#             */
/*   Updated: 2023/02/02 11:38:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_H
# define AMATERIA_H

#include <iostream>
#include <string>
class AMateria;
#include "ICharacter.hpp"

class AMateria
{
	public:
		AMateria();
		AMateria( std::string const & type );
		AMateria( AMateria const & src );
		virtual ~AMateria();

		AMateria &			operator=( AMateria const & rhs );

		std::string const &	getType() const;

		virtual AMateria*	clone() const = 0;
		virtual void		use( ICharacter& target );

	protected:
		std::string			_type;
};

#endif