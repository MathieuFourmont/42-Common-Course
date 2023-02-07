/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:44:32 by mmaxime-          #+#    #+#             */
/*   Updated: 2023/02/02 14:44:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef IMATERIASOURCE_H
# define IMATERIASOURCE_H

#include <iostream>
#include "AMateria.hpp"

class IMateriaSource
{
	public:
		virtual ~IMateriaSource() {}

		virtual void		learnMateria( AMateria* ) = 0;
		virtual AMateria*	createMateria( std::string const & type ) = 0;
};

#endif