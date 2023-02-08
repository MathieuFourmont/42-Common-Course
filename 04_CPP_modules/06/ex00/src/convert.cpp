/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:48:21 by marvin            #+#    #+#             */
/*   Updated: 2023/02/08 15:48:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/convert.hpp"

// CONSTRUCTORS AND DESTRUCTOR //

convert::convert() // constructeur privé
{
	return ;
}

convert::convert( std::string const literal )
{
	for( int i = 0; i < NB_TYPE_CONVERSION; i++ )
		_convert_table[i].status = NOT_CONVERTED;
	_convert_table[T_CHAR].convertFunction = &convert::convertToChar;
	_convert_table[T_INT].convertFunction = &convert::convertToInt;
	_convert_table[T_FLOAT].convertFunction = &convert::convertToFloat;
	_convert_table[T_DOUBLE].convertFunction = &convert::convertToDouble;
	_convert_table[T_NA].convertFunction = &convert::allImpossible;

	// permet d'appeler la fonction correspondante au type de literal
	( this->*( _convert_table[getType( literal )].convertFunction ) )( literal );
}

convert::convert( convert const & src )
{
	for( int i = 0; i < NB_TYPE_CONVERSION; i++ )
		_convert_table[i].status = src._convert_table[i].status;
	_converted = src._converted;
}

convert::~convert()
{
	return ;
}

// OVERLOADS //

convert &	convert::operator=( convert const & rhs )
{
	if ( this != &rhs )
	{
		for ( int i = 0; i < NB_TYPE_CONVERSION; i++ )
			_convert_table[i].status = rhs._convert_table[i].status;
		_converted = rhs._converted;
	}
	return ( *this );
}

// MEMBER FUNCTIONS //

convert::t_types	convert::getType( std::string const & literal )
{
	if ( isChar( literal ) )
		return ( T_CHAR );
	else if ( isInt( literal ) )
		return ( T_INT);
	else if ( isFloat( literal ) )
		return ( T_FLOAT );
	else if ( isDouble( literal ) )
		return ( T_DOUBLE );
	else
		return ( T_NA );	
}

bool	convert::isChar( std::string const & literal )
{
	if ( literal.length() == 1 && !std::isdigit( literal[0] ) )
		return ( true );
	else
		return ( false );
}

bool	convert::isInt( std::string const & literal )
{
	int len = literal.length();
	int	i;

	if ( literal[0] == '-' )
		i = 1;
	else
		i = 0;
	if ( len == i ) // check si empty ou juste - (-> isChar)
		return ( false );
	for (; i < len ; i++ )
		if ( !std::isdigit( literal[i] ) )
			return ( false );
	return ( true );
}

bool	convert::isFloat( std::string const & literal )
{
	size_t	i = 0;

	if ( literal == "-inff" || literal == "+inff" || literal == "nanf" )
		return ( true );
	if ( literal[0] == '-' )
		i++;
	while ( std::isdigit( literal[i] ) )
		i++;
	if ( i + 1 == literal.length() && literal[i] == 'f' )
		return ( true );
	if ( i + 1 == literal.length() && literal[i] != '.' )
		return ( false );
	else
		i++;
	while ( std::isdigit( literal[i] ) )
		i++;
	if ( i + 1 != literal.length() || literal[i] != 'f' )
		return ( false );
	return ( true ); 
}

bool	convert::isDouble( std::string const & literal )
{
	size_t	i = 0;

	if ( literal == "-inf" || literal == "+inf" || literal == "nan" )
		return ( true );
	if ( literal[0] == '-' )
		i++;
	while ( std::isdigit( literal[i] ) )
		i++;
	if ( literal[i] != '.' )
		return ( false );
	i++;
	while ( std::isdigit( literal[i] ) )
		i++;
	if ( i != literal.length() )
		return ( false );
	return ( true );
}

convert::t_status	convert::setCharStatus( char const & c )
{
	if ( std::isprint( c ) )
		return ( CONVERTED );
	else
		return ( NON_DISPLAYABLE );
}

std::string	convert::convertToStr( int integer )
{
	std::string convertedStr; // valeur de retour pour le stream
	std::stringstream stringStream; // stringstram dans lequel effectuer la conversion

	stringStream << integer; // on met l'int dans le stream
	stringStream >> convertedStr; // ensuite on met le contenu du stream (l'int converti en string) dans la valeur de retour
	return ( convertedStr );
}

/*
	Lien pour comprendre la stringstream conversion
		https://www.softwaretestinghelp.com/stringstream-class-in-cpp/#:~:text=The%20stringstream%20class%20in%20C%2B%2B,like%20cin%20and%20cout%20streams.
*/

void	convert::convertToChar( std::string const &literal )
{
	// Conversion du char
	std::stringstream	stringStream( literal );
	stringStream >> _converted.c;
	_convert_table[T_CHAR].status = setCharStatus( _converted.c );

	// explicit conversion dans les autres types
	_converted.i = static_cast<int>( _converted.c );
	_convert_table[T_INT].status = CONVERTED;
	_converted.f = static_cast<float>( _converted.c );
	_convert_table[T_FLOAT].status = CONVERTED;
	_converted.d = static_cast<double>( _converted.c );
	_convert_table[T_DOUBLE].status = CONVERTED;
	return ;
}

void	convert::convertToInt( std::string const &literal )
{
	// Conversion de l'int
	std::stringstream	stringStream( literal );
	stringStream >> _converted.i;
	if ( convertToStr( _converted.i ) != literal )
		allImpossible( literal );
	else
	{
		_convert_table[T_INT].status = CONVERTED;

		// explicit conversion dans les autres type
		_converted.c = static_cast<char>( _converted.i );
		_convert_table[T_CHAR].status = setCharStatus( _converted.c );
		_converted.f = static_cast<float>( _converted.i );
		_convert_table[T_FLOAT].status = CONVERTED;
		_converted.d = static_cast<double>( _converted.i );
		_convert_table[T_DOUBLE].status = CONVERTED;
	}
	return ;
}

void	convert::convertToFloat( std::string const &literal )
{
	// Conversion du float
	if ( literal == "+inff" )
		_converted.f = 1. / 0.;
	else if ( literal == "-inff" )
		_converted.f = -1. / 0.;
	else if ( literal == "nanf" )
		_converted.f = std::numeric_limits<float>::quiet_NaN();
	else
		_converted.f = setFloat( literal );
	_convert_table[T_FLOAT].status = CONVERTED;

	// explicit conversion dans les autres types
	_converted.i = static_cast<int>( _converted.f );
	if ( _converted.i != static_cast<long long>( _converted.f ) )
	{
		_convert_table[T_INT].status = IMPOSSIBLE;
		_convert_table[T_CHAR].status = IMPOSSIBLE;
	}
	else
	{
		_convert_table[T_INT].status = CONVERTED;
		_converted.c = static_cast<char>( _converted.f );
		_convert_table[T_CHAR].status = setCharStatus( _converted.c );
	}
	_converted.d = static_cast<double>( _converted.f );
	_convert_table[T_DOUBLE].status = CONVERTED;
	return ;
}

float	convert::setFloat( std::string const &literal )
{
	std::stringstream	stringStream( literal );
	double				tmp;

	stringStream >> tmp;
	if ( tmp > std::numeric_limits<float>::max() )
		return ( 1./0. );
	else
		return ( (float)tmp );
}

double	convert::setDouble( std::string const &literal )
{
	std::stringstream	stringStream( literal );
	long double			tmp;

	stringStream >> tmp;
	if ( tmp > std::numeric_limits<double>::max() )
		return ( 1./0. );
	else
		return ( (double)tmp );
}


void	convert::convertToDouble( std::string const &literal )
{
	// conversion du double
	if ( literal == "+inf" )
		_converted.d = 1. / 0.;
	else if ( literal == "-inf" )
		_converted.d = -1. / 0.;
	else if ( literal == "nan" )
		_converted.d = std::numeric_limits<double>::quiet_NaN();
	else
		_converted.d = setDouble( literal );
	_convert_table[T_DOUBLE].status = CONVERTED;

	// explicit conversion dans les autres types
	_converted.i = static_cast<int>( _converted.d );
	if ( _converted.i != static_cast<long long>( _converted.d ) )
	{
		_convert_table[T_INT].status = IMPOSSIBLE;
		_convert_table[T_CHAR].status = IMPOSSIBLE;
	}
	else
	{
		_convert_table[T_INT].status = CONVERTED;
		_converted.c = static_cast<char>( _converted.d );
		_convert_table[T_CHAR].status = setCharStatus( _converted.c );
	}
	_converted.f = static_cast<float>( _converted.d );
	_convert_table[T_FLOAT].status = CONVERTED;
	return ;
}

void	convert::allImpossible( std::string const &literal )
{
	(void)literal;
	for ( size_t i = 0; i < NB_TYPE_CONVERSION; i++ )
		_convert_table[i].status = IMPOSSIBLE;
	return ;
}

void	convert::printConvert() const
{
	std::cout << "char: ";
	if ( !printError( _convert_table[T_CHAR].status ) )
		std::cout << "'" << _converted.c << "'" << std::endl;
	std::cout << "int: ";
	if ( !printError( _convert_table[T_INT].status ) )
		std::cout << _converted.i << std::endl;
	std::cout << "float: ";
	if ( !printError( _convert_table[T_FLOAT].status ) )
		std::cout << std::fixed << std::setprecision( 1 ) << _converted.f << "f" << std::endl;
	std::cout << "double: ";
	if ( !printError( _convert_table[T_DOUBLE].status ) )
		std::cout << std::fixed << std::setprecision( 1 ) << _converted.d << std::endl;
	return ;
}

bool	convert::printError( int status ) const
{
	switch ( status )
	{
		case IMPOSSIBLE:
			std::cout << "impossible" << std::endl;
			return ( true );
		case NON_DISPLAYABLE:
			std::cout << "Non displayable" << std::endl;
			return ( true );
		default:
			return ( false );
	}
}