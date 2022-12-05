/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 19:32:35 by mmaxime-          #+#    #+#             */
/*   Updated: 2022/11/02 19:32:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	this->_array[0] = "DEBUG";
	this->_array[1] = "INFO";
	this->_array[2] = "WARNING";
	this->_array[3] = "ERROR";
}

Harl::~Harl()
{

}

void	Harl::complain( std::string level )
{
	size_t	i = 0;

	while ( i < 4 && level.compare( this->_array[i] ) )
		i++;
	switch ( i )
	{
		case 0:
			this->debug();
			std::cout << std::endl;
			this->info();
			std::cout << std::endl;
			this->warning();
			std::cout << std::endl;
			this->error();
			break ;
		case 1:
			this->info();
			std::cout << std::endl;
			this->warning();
			std::cout << std::endl;
			this->error();
			break ;
		case 2:
			this->warning();
			std::cout << std::endl;
			this->error();
			break ;
		case 3:
			this->error();
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
	return ;
}

void	Harl::debug( void )
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do !" << std::endl;
	return ;
}

void	Harl::info( void )
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !" << std::endl;
	return ;
}

void	Harl::warning( void )
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
	return ;
}

void	Harl::error( void )
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable ! I want to speak to the manager now." << std::endl;
	return ;
}