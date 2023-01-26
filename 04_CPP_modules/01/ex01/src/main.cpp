/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <mmaxime-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:07:53 by mmaxime-          #+#    #+#             */
/*   Updated: 2023/01/26 11:07:53 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

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