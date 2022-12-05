/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 18:00:33 by mmaxime-          #+#    #+#             */
/*   Updated: 2022/10/05 18:00:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{

}

Contact::~Contact()
{

}

bool	Contact::set_new_contact( void )
{
	Contact	new_contact;
	bool	ret;

	ret = true;
	std::cout << std::endl << "Please create a new contact, by giving all the following information" << std::endl;
	std::cout << "First name: ";
	std::getline(std::cin, new_contact._first_name);
	if (!std::cin.good() || new_contact._first_name.empty())
		ret = false;
	std::cout << "Last name: ";
	std::getline(std::cin, new_contact._last_name);
	if (!std::cin.good() || new_contact._last_name.empty())
		ret = false;
	std::cout << "Nickname: ";
	std::getline(std::cin, new_contact._nickname);
	if (!std::cin.good() || new_contact._nickname.empty())
		ret = false;
	std::cout << "Phone number: ";
	std::getline(std::cin, new_contact._phone_number);
	if (!std::cin.good() || new_contact._phone_number.empty())
		ret = false;
	std::cout << "Darkest secret: ";
	std::getline(std::cin, new_contact._darkest_secret);
	if (!std::cin.good() || new_contact._darkest_secret.empty())
		ret = false;
	*this = new_contact;
	return (ret);
}

std::string	Contact::get_first_name( void ) const
{
	return this->_first_name;
}
std::string	Contact::get_last_name( void ) const
{
	return this->_last_name;
}
std::string	Contact::get_nickname( void ) const
{
	return this->_nickname;
}
std::string	Contact::get_phone_number( void ) const
{
	return this->_phone_number;
}
std::string	Contact::get_darkest_secret( void ) const
{
	return this->_darkest_secret;
}

void	Contact::display_summarized_contact( size_t width ) const
{
	if (this->_first_name.size() > width)
		std::cout << this->_first_name.substr(0, width - 1) << "." << "|";
	else
		std::cout << std::setw(width) << this->_first_name << "|";
	if (this->_last_name.size() > width)
		std::cout << this->_last_name.substr(0, width - 1) << "." << "|";
	else
		std::cout << std::setw(width) << this->_last_name << "|";
	if (this->_nickname.size() > width)
		std::cout << this->_nickname.substr(0, width - 1) << "." << "|";
	else
		std::cout << std::setw(width) << this->_nickname << "|";
	return ;
}

void	Contact::display_contact( void ) const
{
	std::cout << "First name: " << this->_first_name << std::endl;
	std::cout << "Last name: " << this->_last_name << std::endl;
	std::cout << "Nickname: " << this->_nickname << std::endl;
	std::cout << "Phone number: " << this->_phone_number << std::endl;
	std::cout << "Darkest secret: " << this->_darkest_secret << std::endl;
	return ;
}