/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <mmaxime-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 18:07:01 by mmaxime-          #+#    #+#             */
/*   Updated: 2022/12/05 18:07:01 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>
#include <math.h>

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
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

		// Operator overload
		Fixed &	operator=( Fixed const & rhs );

		// Member functions
		float	toFloat( void ) const;
		int		toInt( void ) const;
		
	private:
		int					_n;
		static int const	_binaryPoint = 8;

};

// Opérateur d'affichage (impossible d'utiliser la syntaxe des fonctions membres pour faire une surcharge de <<)
std::ostream &	operator<<( std::ostream & o, Fixed const & rhs);

# endif