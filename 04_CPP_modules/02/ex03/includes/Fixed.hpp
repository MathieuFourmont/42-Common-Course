/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <mmaxime-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:27:54 by mmaxime-          #+#    #+#             */
/*   Updated: 2023/01/26 11:27:54 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
	public:
		// Constructors & destructor
		Fixed();
		Fixed( int const i );
		Fixed( float const f );
		Fixed( Fixed const & src );
		~Fixed();

		// Accessor
		int						getRawBits( void ) const;
		void					setRawBits( int const raw );

		// Operator overload
		Fixed &					operator=( Fixed const & rhs );
		Fixed					operator+( Fixed const & rhs ) const;
		Fixed					operator-( Fixed const & rhs ) const;
		Fixed					operator*( Fixed const & rhs ) const;
		Fixed					operator/( Fixed const & rhs ) const;
		
		bool					operator>( Fixed const & rhs ) const;
		bool					operator<( Fixed const & rhs ) const;
		bool					operator>=( Fixed const & rhs ) const;
		bool					operator<=( Fixed const & rhs ) const;
		bool					operator==( Fixed const & rhs ) const;
		bool					operator!=( Fixed const & rhs ) const;
		
		Fixed					operator++( int ); // i++
		Fixed & 				operator++(); // ++i
		Fixed					operator--( int );
		Fixed & 				operator--();

		// Member functions
		float					toFloat( void ) const;
		int						toInt( void ) const;
		static Fixed &			min( Fixed & x, Fixed & y );
		static Fixed const &	min( Fixed const & x, Fixed const & y );
		static Fixed &			max( Fixed & x, Fixed & y );
		static Fixed const &	max( Fixed const & x, Fixed const & y );

	private:
		int						_n;
		static int const		_binaryPoint = 8;

};

// Opérateur d'affichage (impossible d'utiliser la syntaxe des fonctions membres pour faire une surcharge de <<)
std::ostream &					operator<<( std::ostream & o, Fixed const & rhs);

# endif