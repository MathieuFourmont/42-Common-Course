/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <mmaxime-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 11:34:17 by mmaxime-          #+#    #+#             */
/*   Updated: 2023/02/15 14:17:05 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/iter.hpp"

int main()
{
    int     tab[10] = { 1, 2, -4, 4, 222222222, 6, 7, 8, 9, 7 };
    char    tab2[] = "Hello World!";

    iter( tab, 10, display );
    std::cout << std::endl;
    iter( tab2, 13, display );
    std::cout << std::endl;
    iter( tab2, 13, toUpperCase );
    std::cout << std::endl;
    iter( tab, 10, multiply );

    return ( 0 );
}