/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 10:51:10 by mmaxime-          #+#    #+#             */
/*   Updated: 2022/10/28 10:51:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	Zombie	Zombie1 = Zombie("Math_stack");
	Zombie*	Zombie2 = newZombie("Math_heap");

	Zombie1.announce();
	randomChump("Math_random");
	delete Zombie2;
	return(0);
}