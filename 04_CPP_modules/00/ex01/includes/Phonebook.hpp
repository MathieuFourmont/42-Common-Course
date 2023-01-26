/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <mmaxime-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:10:55 by mmaxime-          #+#    #+#             */
/*   Updated: 2022/12/05 10:10:55 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H
# define MAX_CONTACTS 8

#include <iostream>
#include <string>
#include <iomanip>
#include "Contact.hpp"

class Phonebook
{
	public:
		Phonebook(); //constructeur -> fonction appelée pour initialiser la classe
		~Phonebook(); //destructeur -> fonction appelée lorsque l'on va détruire la classe, c'est ici aussi qu'on utilisera "delete" pour désallouer la mémoire dynamiquement allouée
		void	add_contact( void );
		void	search_contact( void ) const; // const permet de caster en "lectiure seule", cette méthode ne fera que lire les attributs de l'objet et ne le modifiera donc pas

	private:
		Contact	_contact[MAX_CONTACTS];
		int		_contacts_nb;
		void	_display_phonebook( void ) const;
};


#endif