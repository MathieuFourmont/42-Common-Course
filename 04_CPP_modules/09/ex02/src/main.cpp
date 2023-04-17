/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <mmaxime-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 16:05:29 by mmaxime-          #+#    #+#             */
/*   Updated: 2023/04/17 16:05:31 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

bool	checkPositive( int argc, char **argv )
{
	int	i;
	int nb;

	for ( i = 0; i < argc; ++i )
	{
		nb = atoi(argv[i])
		if ( nb <= 0 )
			return ( false );
	}
	return ( true );
}

int	main( int argc, char ** argv )
{
	if (argc < 2 || checkPositive( argc, argv ) )
	{
		std::cout << "Error: please provide a positive integer sequence" << std::endl;
		return ( 1 );
	}
}