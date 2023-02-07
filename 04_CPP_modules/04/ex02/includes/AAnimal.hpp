/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <mmaxime-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:00:38 by mmaxime-          #+#    #+#             */
/*   Updated: 2023/01/26 11:00:38 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_H
# define AANIMAL_H

#include <iostream>
#include <string>

class AAnimal // préfixe A = convention pour indiquer que la classe est abstraite.
// classe abrstaite = certains comportements sont définis, et d'autres ne le sont pas + la classe elle même ne peut pas être instanciée
// une classe est abstraite lorsqu'elle possède au moins une fonction membre virtuelle pure 
// pour pouvoir être instanciée, une classe qui hérite de cette classe abstraite (ex: Dog) va devoir implémenter les comportements définis comme abstraits dans la parent
{
	public:
		AAnimal();
		AAnimal( AAnimal const & src );
		virtual ~AAnimal();

		AAnimal &			operator=( AAnimal const & rhs );

		std::string const	getType() const;
		virtual void		makeSound() const = 0; // fonction membre virtuelle pure

	protected:
		std::string			type;
};

#endif