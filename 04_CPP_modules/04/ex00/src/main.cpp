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

#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"

int	main()
{
	const Animal*		unknown = new Animal();
	const Animal*		bob = new Dog();
	const Animal*		felix = new Cat();
	const WrongAnimal*	wrongFelix = new WrongCat();

	std::cout << bob->getType() << " " << std::endl;
	bob->makeSound();
	std::cout << felix->getType() << " " << std::endl;
	felix->makeSound();
	unknown->makeSound();
	wrongFelix->makeSound();

	std::cout << std::endl;

	delete( unknown );
	delete( bob );
	delete( felix );
	delete( wrongFelix );

	return ( 0 );
}