/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 20:13:06 by marvin            #+#    #+#             */
/*   Updated: 2023/02/08 20:13:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Base.hpp"
#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"

int	main()
{
	int	nbOfTest = 10;

	for ( int i = 0; i < nbOfTest; i++ )
	{
		Base*	test = generate();

		std::cout << "Test " << i << std::endl;
		std::cout << "Identify(ptr): ";
		identify( test );
		std::cout << std::endl;

		std::cout << "Identify(ref): ";
		identify( *test );
		std::cout << std::endl << std:: endl;

		delete test;
	}

	return ( 0 );
}

Base*	generate()
{
	static bool	seedSet = false;

	if ( !seedSet )
	{
		srand( time( 0 ) );
		seedSet = true ; // besoin d'initialiser le seed qu'une seule fois
	}

	int			randomBase = rand() % 3; // pour avoir une valeur au hasard entre 0 et 2

	if ( randomBase == 0 )
		return ( new A );
	else if ( randomBase == 1 )
		return ( new B );
	else
		return ( new C ); 
}

void	identify( Base* p)
{
	if ( p == NULL )
		return ;
	else if ( dynamic_cast<A*>( p ) != NULL ) // renvoie NULL dans le cas où la conversion n'est pas possible
		std::cout << "A";
	else if ( dynamic_cast<B*>( p ) != NULL )
		std::cout << "B";
	else if ( dynamic_cast<C*>( p ) != NULL )
		std::cout << "C";
	else
		return ;
	return;
}

void	identify( Base& p)
{
	try
	{
		Base&	comparison = dynamic_cast<A&>( p );
		std::cout << "A";
		(void)comparison;
	}
	catch(const std::exception& e)
	{

	}
	try
	{
		Base&	comparison = dynamic_cast<B&>( p );
		std::cout << "B";
		(void)comparison;
	}
	catch(const std::exception& e)
	{

	}
	try
	{
		Base&	comparison = dynamic_cast<C&>( p );
		std::cout << "C";
		(void)comparison;
	}
	catch(const std::exception& e)
	{

	}
	return ;
}