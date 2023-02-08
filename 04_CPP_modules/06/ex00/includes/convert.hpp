/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:49:19 by marvin            #+#    #+#             */
/*   Updated: 2023/02/08 15:49:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_H
# define CONVERT_H

#include <cstdlib>
#include <string>
#include <iostream>
#include <iomanip> // std::precision, std::fixed
#include <limits> // nan(f), +inf(f), -inf(f)
#include <climits>
#include <sstream>

# define NB_TYPE_CONVERSION 4

class convert
{
	public:
		convert( std::string const literal );
		convert( convert const & src );
		~convert();

		convert &	operator=( convert const & rhs );

		void		printConvert() const;

	private:
		// Status + erreur à afficher
		typedef enum e_status
		{
			NOT_CONVERTED = 0,
			IMPOSSIBLE,
			NON_DISPLAYABLE,
			CONVERTED
		}			t_status;

		// Va permettre de déterminer quelle fonction utiliser dans la convert table
		typedef enum e_types
		{
			T_CHAR = 0,
			T_INT,
			T_FLOAT,
			T_DOUBLE,
			T_NA
		}			t_types;

		typedef struct s_convert_table
		{
			t_status	status;
			void		(convert::*convertFunction)( const std::string& );
		}				t_convert_table;

		// Types dans lesquels doit être converti l'input
		typedef struct s_convert
		{
			char	c;
			int		i;
			float	f;
			double	d;
		}				t_convert;

		// VARIABLES //
		t_convert_table	_convert_table[NB_TYPE_CONVERSION + 1];
		t_convert		_converted;

		// MEMBER FUNCTIONS //
		t_types		getType( std::string const & literal );
		bool		isChar( std::string const & literal );
		bool		isInt( std::string const & literal );
		bool		isFloat( std::string const & literal );
		bool		isDouble( std::string const & literal );

		// Checks des limites
		t_status	setCharStatus( char const & c); // displayable?
		std::string	convertToStr( int interger ); // MAX_INT et MIN_INT
		float		setFloat( std::string const &literal ); // FLT_MAX ET FLT_MIN
		double		setDouble( std::string const &literal ); // Double limits

		// Conversions
		void		convertToChar( std::string const &literal );
		void		convertToInt( std::string const &literal );
		void		convertToFloat( std::string const &literal );
		void		convertToDouble( std::string const &literal );
		void		allImpossible( std::string const &literal );

		// Print errors
		bool		printError( int status ) const;

		convert(); // pas besoin de ce constructeur
};

#endif