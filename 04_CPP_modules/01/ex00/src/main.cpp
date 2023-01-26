/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <mmaxime-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:02:56 by mmaxime-          #+#    #+#             */
/*   Updated: 2023/01/26 11:02:56 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

int	main()
{
	Zombie	Zombie1 = Zombie("Math_stack");
	Zombie*	Zombie2 = newZombie("Math_heap");

	Zombie1.announce();
	randomChump("Math_random");
	delete Zombie2;
	return(0);
}