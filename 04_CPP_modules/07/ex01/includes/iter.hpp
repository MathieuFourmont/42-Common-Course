/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <mmaxime-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:59:17 by mmaxime-          #+#    #+#             */
/*   Updated: 2023/02/13 11:22:51 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_H
# define ITER_H

#include <iostream>

template < typename T >
void    iter( T *tab, size_t size, void (*f)( T const & elem ) )
{
    for ( size_t i = 0; i < size; i++ )
        f( tab[i] );
    return ;
}

template < typename T >
void    display( T const & value )
{
    std::cout << value << " ";
    return ;
}

template < typename T >
void    toUpperCase( T const & elem )
{
    char const   c = std::toupper(elem);
    std::cout << c;
    return ;
}

template < typename T >
void    multiply( T const & elem )
{
    int ret = elem * 2;
    std::cout << ret << " ";
}

#endif