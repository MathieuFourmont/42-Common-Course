/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 08:40:52 by marvin            #+#    #+#             */
/*   Updated: 2023/02/06 08:40:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ShrubberyCreationForm.hpp"

// CONSTRUCTORS AND DESTRUCTOR //

ShrubberyCreationForm::ShrubberyCreationForm() : AForm()
{
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) : AForm( "ShrubberyCreationForm", target, 145, 137 )
{
	return ;
}
ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const & src ) : AForm( src )
{
	return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	return ;
}

// OVERLOADS //

ShrubberyCreationForm &	ShrubberyCreationForm::operator=( ShrubberyCreationForm const & rhs )
{
	if ( this != &rhs )
		(void) rhs;
	return ( *this );
}

// MEMBER FUNCTIONS //

void	ShrubberyCreationForm::executeSpecForm() const
{
	std::ofstream	outFile;
	std::string		outFileName;

	outFileName = getTarget() + "_shrubbery";
	try // open utilise des exceptions pour gérer ses erreurs
	{
		outFile.open ( outFileName.c_str(), std::ios_base::out | std::ios_base::trunc ); // ouverture en écriture avec effacement du fichier ouvert
	}
	catch( const std::exception &e )
	{
		std::cerr << e.what() << std::endl;
		return ;
	}
	outFile \
	<< "                   v .   ._, |_  .," << std::endl \
    << "           `-._\\/  .  \\ /    |/_" << std::endl \
    << "               \\  _\\, y | \\//" << std::endl \
    << "         _\\_.___\\, \\/ -.\\||" << std::endl \
    << "           `7-,--.`._||  / / ," << std::endl \
    << "           /'     `-. `./ / |/_.'" << std::endl \
    << "                     |    |//" << std::endl \
    << "                     |_    /" << std::endl \
    << "                     |-   |" << std::endl \
    << "                     |   =|" << std::endl \
    << "                     |    |" << std::endl \
	<< "--------------------/ ,  . \\--------._" << std::endl;
	outFile.close();
	return ;
}