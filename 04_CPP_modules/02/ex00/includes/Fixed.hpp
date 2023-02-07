/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <mmaxime-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:25:17 by mmaxime-          #+#    #+#             */
/*   Updated: 2023/01/26 11:25:17 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

#include <iostream>
#include <string>

class Fixed
// Forme canonique = (au moins)
// - 1 constructeur par défaut
// - 1 constructeur de recopie
// - 1 opérateur d'assignation
// - 1 destructeur
{
	public:
		// Constructeur & destructeur
		Fixed(); // constructeur par défaut
		Fixed( Fixed const & src ); // constructeur de recopie
		~Fixed();

		// Accesseur et setter
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

		// Surcharges d'opérateurs arithmétiques (Operator overload)
		Fixed &	operator=( Fixed const & rhs ); // opérateur d'assignation
		
	private:
		int					_n;
		static int const	_binaryPoint = 8;

};

# endif