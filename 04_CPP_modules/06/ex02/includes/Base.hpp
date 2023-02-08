/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 20:02:23 by marvin            #+#    #+#             */
/*   Updated: 2023/02/08 20:02:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

#include <iostream>
#include <cstdlib> // srand, rand
#include <time.h> // time

class Base
{
	public:
		Base();
		virtual ~Base();
};

Base*	generate();
void	identify( Base* p);
void	identify( Base& p);

#endif