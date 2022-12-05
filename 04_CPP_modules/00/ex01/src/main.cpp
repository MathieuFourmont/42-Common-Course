/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:57:42 by marvin            #+#    #+#             */
/*   Updated: 2022/10/05 10:57:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include "Contact.hpp"

int	main()
{
	std::string	cmd;
	Contact		contact; //c'est une instance de la classe "Contact". En instanciant la classe de la sorte, je vais faire appel automatiquement à son constructeur
	Phonebook	my_phonebook;

	while (1)
	{
		std::cout << "Please enter a command (ADD, SEARCH or EXIT): ";
		std::getline(std::cin, cmd);
		//std::cout << std::endl;
		if (cmd == "EXIT")
		{
			std::cout << std::endl << "Ok, bye ;)" << std::endl << std::endl;
			break;
		}
		if (cmd == "ADD")
			my_phonebook.add_contact();
		if (cmd == "SEARCH")
			my_phonebook.search_contact();
		std::cout << std::endl;
	}
	return (0);
}