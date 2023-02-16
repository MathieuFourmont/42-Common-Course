/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <mmaxime-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 11:56:19 by mmaxime-          #+#    #+#             */
/*   Updated: 2023/02/13 16:37:05 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_H
# define WHATEVER_H

#include <iostream>

template < typename T > void    swap( T & x, T & y )
{
    T   temp;

    temp = x;
    x = y;
    y = temp;
}

template< typename T > T const &    max( T const & x, T const & y )
{
    return ( x > y ? x : y );
}

template< typename T > T const &    min( T const & x, T const & y )
{
    return ( x < y ? x : y );
}

#endif