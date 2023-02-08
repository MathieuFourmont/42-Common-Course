/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:21:29 by marvin            #+#    #+#             */
/*   Updated: 2023/02/08 19:21:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_CPP
# define MAIN_CPP

#include <iostream>

struct Data
{
	std::string	type;
	int			nbOfWheels;
};

typedef unsigned long uintptr_t; // uintptr_t is only an existing type from C++11

uintptr_t	serialize( Data* const ptr );
Data*		deserialize( uintptr_t const raw );
void		printData ( Data const &vehicle);


#endif