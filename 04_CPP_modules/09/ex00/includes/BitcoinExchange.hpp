/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <mmaxime-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 16:04:09 by mmaxime-          #+#    #+#             */
/*   Updated: 2023/04/17 16:04:09 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <exception>
#include <cstdlib>

class BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange( BitcoinExchange const & src );
		~BitcoinExchange();

		BitcoinExchange &				operator=( BitcoinExchange const & rhs );

		void							mapCreation( const char* inputFile );
		void							printValo( const char* inputFile );
		bool							isValidDate( const std::string & date_str ); // checker le nb de char = 10 et si les '-' sont aux bonnes positions, si 0<mois<12 et 0<jour<30 (29 pour février)

	private:
		std::map<std::string, double>	_btcMap;
};

#endif