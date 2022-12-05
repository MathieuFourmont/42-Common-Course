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
	int	zombies_nb = 10;
	Zombie*	zombies;

	zombies = zombieHorde(zombies_nb, "Math");
	for (int i = 0; i < zombies_nb; i++)
		zombies[i].announce();
	delete [] zombies;
	return(0);
}