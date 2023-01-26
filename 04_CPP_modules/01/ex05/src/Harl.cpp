/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <mmaxime-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:23:01 by mmaxime-          #+#    #+#             */
/*   Updated: 2023/01/26 11:23:01 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"

Harl::Harl()
{
	this->f[0] = &Harl::debug;
	this->f[1] = &Harl::info;
	this->f[2] = &Harl::warning;
	this->f[3] = &Harl::error;
}

Harl::~Harl()
{

}

void	Harl::complain( std::string level )
{
	std::string	arrayUpper[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	std::string	arrayLower[4] = {"debug", "info", "warning", "error"};

	for (int i = 0; i < 4; i++)
	{
		if (arrayUpper[i] == level || arrayLower[i] == level)
			(this->*f[i])();
	}
	return ;
}

void	Harl::debug( void )
{
	std::cout << "DEBUG:" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do !" << std::endl;
	return ;
}

void	Harl::info( void )
{
	std::cout << "INFO:" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !" << std::endl;
	return ;
}

void	Harl::warning( void )
{
	std::cout << "WARNING:" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
	return ;
}

void	Harl::error( void )
{
	std::cout << "ERROR:" << std::endl;
	std::cout << "This is unacceptable ! I want to speak to the manager now." << std::endl;
	return ;
}