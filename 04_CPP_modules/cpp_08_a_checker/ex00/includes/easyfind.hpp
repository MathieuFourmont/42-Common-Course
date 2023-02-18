/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <mmaxime-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:40:25 by mmaxime-          #+#    #+#             */
/*   Updated: 2023/02/14 14:10:15 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_H
# define EASYFIND_H

#include <vector>
#include <deque>
#include <list>
#include <algorithm>
#include <iostream>
#include <exception>

template < typename T >
void	easyfind( T container, int toFind )
{
	typename T::iterator it;

	it = std::find( container.begin(), container.end(), toFind );
	if ( it == container.end() )
		throw ( std::exception() );
	else
		std::cout << *it << " has been found!" << std::endl;
	return ;
}

#endif