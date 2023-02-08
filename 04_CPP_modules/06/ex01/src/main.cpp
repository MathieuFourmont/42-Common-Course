/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:14:10 by marvin            #+#    #+#             */
/*   Updated: 2023/02/08 19:14:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.hpp"

int	main()
{
	Data car =
	{
		.type = "car",
		.nbOfWheels = 4
	};

	Data moto =
	{
		.type = "moto",
		.nbOfWheels = 2
	};

	Data tricycle =
	{
		.type = "tricycle",
		.nbOfWheels = 3
	};

	printData( car );
	printData( moto );
	printData( tricycle );

	std::cout << std::endl;
	std::cout << "* Serialization test *" << std::endl;
	std::cout << "Results should appear in the same order than above" << std::endl;
	std::cout << std::endl;

	uintptr_t	ptrCar = serialize( &car );
	printData( *deserialize( ptrCar ) );
	printData( *deserialize( serialize( &moto ) ) );

	uintptr_t	ptrTricycle = serialize( &tricycle );
	Data*	copyTricycle = deserialize( ptrTricycle );
	printData( *copyTricycle );

	return ( 0 );
}

uintptr_t	serialize( Data* const ptr )
{
	return ( reinterpret_cast<uintptr_t>( ptr ) );
}

Data*	deserialize( uintptr_t const raw )
{
	return ( reinterpret_cast<Data*>( raw ) );
}

void	printData ( Data const &vehicle )
{
	std::cout << "Here is a " << vehicle.type << " because it has " << vehicle.nbOfWheels << " wheels" << std::endl;
	return ;
}
