/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <mmaxime-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 16:04:30 by mmaxime-          #+#    #+#             */
/*   Updated: 2023/04/17 16:04:30 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	return ;
}

BitcoinExchange::BitcoinExchange( BitcoinExchange const & src ) : _btcMap( src._btcMap )
{
	return ;
}

BitcoinExchange::~BitcoinExchange()
{
	return ;
}

BitcoinExchange & BitcoinExchange::operator=( BitcoinExchange const & rhs )
{
	if ( this != &rhs )
		_btcMap = rhs._btcMap;
	return ( *this );
}

void	BitcoinExchange::mapCreation( const char* inputFile )
{
	std::string		line;
	int				i;
	std::string		date_str;
	std::string		rate_str;
	double			rate;

	i = 0;
	std::ifstream	ifs( inputFile );
	if ( !ifs || !ifs.is_open() )
		throw std::runtime_error( "Error: could not open file." );
	while ( std::getline( ifs, line ) )
	{
		if ( i++ == 0) // pour ne pas avoir les en-têtes
			continue ;
		std::stringstream	ss( line ); // pour utiliser line comme un stream et ainsi refaire un getline dessus
		std::getline( ss, date_str, ',' ); // pour récupérer la date en str
		std::getline( ss, rate_str ); // le reste après la ',' étant la taux de change
		rate = std::atof( rate_str.c_str() );
		_btcMap[date_str] = rate;
		i++;
	}
	if ( i == 0 || _btcMap.size() == 0 )
	{
		ifs.close();
		throw std::length_error( "Error: empty database." );
	}
	ifs.close();
	// std::map<std::string, double>::iterator	it;
	// for ( it = _btcMap.begin(); it != _btcMap.end(); ++it )
	// {
	// 	std::cout << it->first << " => " << it->second << std::endl;
	// }
}

bool	BitcoinExchange::isValidDate( const std::string & date_str )
{
	int	year;
	int	month;
	int	day;
	int	days_nb;

	if( date_str.length() != 10 )
		return ( false );
	if ( date_str[4] != '-' || date_str[7] != '-' )
		return ( false );
	for ( int i = 0; i < 10; i++ )
	{
		if ( i == 4 || i == 7 )
			continue ;
		if ( !isdigit( date_str[i] ) )
			return ( false );
	}
	if ( sscanf( date_str.c_str(), "%4d-%2d-%2d", &year, &month, &day ) != 3 )
		return ( false );
	if ( year < 1900 || year > 9999 || month < 1 || month > 12 )
		return ( false );
	days_nb = 31;
	if ( month == 2 )
		days_nb = 29;
	else if ( month == 4 || month == 6 || month == 9 || month == 11 )
		days_nb = 30;
	if ( day < 1 || day > days_nb )
		return ( false );
	return ( true );
}

static std::string	eraseSpaces( const std::string & str )
{
	std::size_t	last;

	last = str.find_last_not_of( " " );
	if ( last == std::string::npos )
		return ( "" );
	return ( str.substr( 0, last + 1 ) );
}

void	BitcoinExchange::printValo( const char* inputFile )
{
	int				i;
	std::string		line;
	//std::string		date_str;
	//std::string		amount_str;
	//double			amount;
	//double			value;

	i = 0;
	std::ifstream	ifs( inputFile );
	if ( !ifs || !ifs.is_open() )
		throw std::runtime_error( "Error: could not open file." );
	while ( std::getline( ifs, line ) )
	{
		if ( i++ == 0 )
			continue ;
		std::stringstream	ss( line );
		std::string			date_str;
		std::string			amount_str;

		std::getline( ss, date_str, '|' );
		if ( !isValidDate( eraseSpaces( date_str ) ) )
		{
			std::cerr << "Error: bad input => " << date_str << std::endl;
			continue ;
		}
		std::getline( ss, amount_str );
		if ( amount_str.empty() )
		{
			std::cerr << "Error: empty amount." << std::endl;
			continue ;
		}
		double amount = std::atof( amount_str.c_str() );
		if ( amount < 0 || ( amount == 0 && amount_str != "0" ) )
		{
			std::cerr << "Error: not a positive number." << std::endl;
			continue ;
		}
		else if ( amount > 1000 )
		{
			std::cerr << "Error: too large a number." << std::endl;
			continue ;
		}
		std::map<std::string, double>::iterator	it = _btcMap.lower_bound( date_str ); // retourne un itérateur pointant sur la 1ère clé ne dépassant pas date_str (si celle-ci n'est pas trouvée)
		if ( it != _btcMap.begin() )
			--it;
		double value = amount * it->second;
		std::cout << date_str << "=>" << amount_str << " = " << value << std::endl;
		i++;
	}
	if ( i == 0 )
	{
		ifs.close();
		throw std::length_error( "Error: empty file." );
	}
	ifs.close();
}