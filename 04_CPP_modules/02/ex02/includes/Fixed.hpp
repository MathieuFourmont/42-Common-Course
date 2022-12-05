/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 09:33:12 by mmaxime-          #+#    #+#             */
/*   Updated: 2022/11/03 09:33:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

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
		Fixed( int const n); // constructeur paramétrique
		Fixed( Fixed const & src ); // constructeur de recopie
		~Fixed();

		// Accesseur
		int	getValue( void ) const;

		// Surcharges d'opérateurs de comparaison


		// Surcharges d'opérateurs arithmétiques (Operator overload)
		Fixed &	operator=( Fixed const & rhs ); // opérateur d'assignation
		Fixed	operator+( Fixed const & rhs ) const; // membre gauche, caché, est l'instance courante (this) et le membre droit est rhs (Right Hand Side)
		Fixed	operator-( Fixed const & rhs ) const;
		Fixed	operator*( Fixed const & rhs ) const;
		Fixed	operator/( Fixed const & rhs ) const;

		// Surcharges d'opérateurs d'incrémentation et décrémentation

	private:
		int	_n;

};

// Opérateur d'affichage (impossible d'utiliser la syntaxe des fonctions membres pour faire une surcharge de <<)
std::ostream &	operator<<( std::ostream & o, Fixed const & rhs);

# endif