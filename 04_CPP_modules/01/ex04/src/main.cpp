/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 10:04:31 by mmaxime-          #+#    #+#             */
/*   Updated: 2022/11/02 10:04:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

int	main( int argc, char **argv )
{
	if( argc != 4 )
	{
		std::cout << "Usage: <filename> <""string_1""> <""string_2""> " << std::endl;
		return ( 1 );
	}
	std::string			filename = argv[1];
	std::string			fileCopied = filename + ".replace";
	std::string			toReplace = argv[2];
	size_t				pos = 0;
	std::string			substitute = argv[3];
	std::ifstream		inputFile;
	std::ofstream		outputFile;
	std::stringstream	buffer;
	std::string			searchIn;

	inputFile.open( filename.c_str(), std::ifstream::in );
	if( !inputFile.is_open() || inputFile.fail() )
	{
		std::cout << "File can´t be openned or doesn´t exist." << std::endl;
		return ( 2 );
	}
	outputFile.open( fileCopied.c_str(), std::ofstream::out | std::ofstream::trunc ); // pour effacer ce que contient le fichier, s'il contient qq chose
	if ( !outputFile.is_open() || outputFile.fail() )
	{
		std::cout << "File can´t be openned or doesn´t exist." << std::endl;
		inputFile.close();
		return ( 3 );
	}
	buffer << inputFile.rdbuf(); // sans cette manip (avec ligne du dessous, s'il y plusieurs lignes dans le fichier, seulement la 1ère ligne aurait été checkée)
	searchIn = buffer.str();
		while ( (pos = searchIn.find( toReplace, pos )) != std::string::npos )
		{
			searchIn.erase( pos, toReplace.size() );
			searchIn.insert( pos, substitute );
			pos += substitute.size();
	}
	outputFile << searchIn;
	inputFile.close();
	outputFile.close();
	return ( 0 );
}