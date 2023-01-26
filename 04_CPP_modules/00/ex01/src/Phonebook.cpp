/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <mmaxime-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:11:32 by mmaxime-          #+#    #+#             */
/*   Updated: 2022/12/05 10:11:32 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Phonebook::Phonebook() : _contacts_nb(0)
{

}

Phonebook::~Phonebook()
{

}

void	Phonebook::add_contact( void )
{
	int		index;

	index = this->_contacts_nb;
	while (index >= MAX_CONTACTS)
		index -= MAX_CONTACTS;
	if (this->_contact[index].set_new_contact() == true)
	{
		std::cout << std::endl << "Congrats, the contact has been added to the phonebook!" << std::endl;
		_contacts_nb++;
	}
	else
		std::cout << std::endl << "Woops, there is an empty field, contact not created" << std::endl;
}

void	Phonebook::search_contact ( void ) const
{
	std::string	index;

	if (this->_contacts_nb == 0)
	{
		std::cout << std::endl << "Sorry, this phonebook is empty" << std::endl;
		return ;
	}
	this->_display_phonebook();
	std::cout << std::endl << "Please enter an index number: ";
	std::getline(std::cin, index);
	if (!std::cin.good())
		return ;
	if (index.size() != 1 || index.at(0) < '1' || (int)index.at(0) - '0' > this->_contacts_nb || (int)index.at(0) - '0' > MAX_CONTACTS)
		std::cout << "Sorry, there is no contact with this index number" << std::endl;
	else
		this->_contact[index.at(0) - '0' - 1].display_contact();
	return ;
}

void	Phonebook::_display_phonebook( void ) const
{
	int		index;
	size_t	width;

	index = 1;
	width = 10;
	std::cout << std::endl;
	std::cout << "Index     |First name|Last name |Nickname  |" << std::endl;
	std::cout << "----------|----------|----------|----------|" << std::endl;
	while (index <= _contacts_nb && index <= MAX_CONTACTS)
	{
		std::cout << std::setw(width) << index << "|";
		_contact[index - 1].display_summarized_contact(width);
		std::cout << std::endl;
		index++;
	}
	std::cout << "----------|----------|----------|----------|" << std::endl;
}
