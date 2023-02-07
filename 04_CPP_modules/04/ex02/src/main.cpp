/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <mmaxime-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:02:05 by mmaxime-          #+#    #+#             */
/*   Updated: 2023/01/26 11:02:05 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AAnimal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"

int	main()
{
	//AAnimal*	undefined = new AAnimal(); // ne doit pas fonctioner car définie comme abstraite -> ne peut pas être instanciée
	AAnimal*	bob = new Dog();
	AAnimal*	felix = new Cat();

	std::cout << std::endl;

	// std::cout << undefined->makeSound() << " " << std::endl; // ne doit pas fonctionner car méthode définie pure
	std::cout << bob->getType() << " " << std::endl;
	bob->makeSound();
	std::cout << felix->getType() << " " << std::endl;
	felix->makeSound();

	std::cout << std::endl;

	// delete( undefined );
	delete( bob );
	delete( felix );
	
	return ( 0 );
}