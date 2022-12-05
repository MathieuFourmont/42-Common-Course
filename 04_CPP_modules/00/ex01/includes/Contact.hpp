/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:12:38 by mmaxime-          #+#    #+#             */
/*   Updated: 2022/10/05 11:12:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

#include <iostream>
#include <string>
#include <iomanip>

class Contact
{
	public: //l'attribut ou la méthode peut être appelé depuis l'extérier de l'objet, au début, on va mettre le méthode en public et les attributs en privé
		Contact();
		~Contact();

		bool		set_new_contact( void );
		std::string	get_first_name( void ) const;
		std::string	get_last_name( void ) const;
		std::string	get_nickname(void ) const;
		std::string	get_phone_number( void ) const;
		std::string	get_darkest_secret( void ) const;
		void		display_summarized_contact( size_t width ) const;
		void		display_contact ( void ) const;

	private: //l'attribut ou la méthode ne peut pas être appelé depuis l'extérier de l'objet, ex : dans le main (classe par défaut si nn spécifiée)
		std::string	_first_name;
		std::string	_last_name;
		std::string	_nickname;
		std::string	_phone_number;
		std::string	_darkest_secret;
};

#endif