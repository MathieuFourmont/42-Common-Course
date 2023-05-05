/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 16:05:29 by mmaxime-          #+#    #+#             */
/*   Updated: 2023/05/05 12:26:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

bool	isInt( char **argv)
{
	int	size;

	for (int i = 1; argv[i]; i++ )
	{
		size = strlen( argv[i] );
		for ( int j = 0; j < size; j++ )
		{
			if ( !isdigit( argv[i][j] ) )
				return ( false );
		}
	}
	return ( true );
}

bool	checkPositive( int argc, char **argv )
{
	int	i;
	int nb;

	for ( i = 1; i < argc; i++ )
	{
		nb = atoi( argv[i] );
		if ( nb <= 0 )
			return ( false );
	}
	return ( true );
}

int	main( int argc, char **argv )
{
	if ( argc < 2 || isInt( argv ) == false || checkPositive( argc, argv ) == false )
	{
		std::cout << "Error: please provide a positive integer sequence" << std::endl;
		return ( 1 );
	}

	std::vector<int>	vector;
	std::deque<int>		deque;

	for ( int i = 1; i < argc; ++i )
		vector.push_back( atoi( argv[i] ) );
	for ( int i = 1; i < argc; ++i )
		deque.push_back( atoi( argv[i] ) );
	
	PmergeMe	toSort( vector, deque );

	std::cout << "Before: ";
	toSort.printVec();

	clock_t	vectorStart = clock();
	toSort.mergeInsertSortPmergeMeVec();
	clock_t	vectorEnd = clock();
	double	vecExecTime = static_cast<double>( vectorEnd - vectorStart ) / CLOCKS_PER_SEC * 1000000;
	
	std::cout << "After: ";
	toSort.printVec();

	clock_t	dequeStart = clock();
	toSort.mergeInsertSortPmergeMeDeq();
	clock_t	dequeEnd = clock();
	double	deqExecTime = static_cast<double>( dequeEnd - dequeStart ) / CLOCKS_PER_SEC * 1000000;

	std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector : " << vecExecTime << " us" << std::endl;
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::deque : " << deqExecTime << " us" << std::endl;

	return ( 0 );
}