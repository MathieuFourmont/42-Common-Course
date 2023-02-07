/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:49:04 by mmaxime-          #+#    #+#             */
/*   Updated: 2023/02/02 11:49:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_H
# define ICE_H

#include <iostream>
#include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice();
		Ice( Ice const & src );
		~Ice();

		Ice &		operator=( Ice const & rhs );

		AMateria*	clone() const;
		void		use( ICharacter& target );

	private:
		/* data */
};

#endif