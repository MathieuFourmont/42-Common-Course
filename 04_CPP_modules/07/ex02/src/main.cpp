/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <mmaxime-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 10:22:21 by mmaxime-          #+#    #+#             */
/*   Updated: 2023/02/15 14:23:46 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/Array.hpp"

#define MAX_VAL 10

// Tests from 42 cpp07
int main()
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];

    srand(time(NULL));

    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    
    std::cout << "Test Array generation" << std::endl << "array[] numbers: ";
    printArray( numbers, MAX_VAL );

    std::cout << std::endl << "array[] mirror: ";
    printTypeArray( numbers, MAX_VAL );
    std::cout << std::endl << std::endl;
    
    // Testing deep copy    
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
        std::cout << "Test Deep Copy" << std::endl << "array[] test: ";
        printArray( numbers, MAX_VAL );
        std::cout << std::endl << std::endl;
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    std::cout << "Trying to access array[-2]. Sould return an exception." << std::endl;
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    std::cout << "Trying to access array[MAX_VALUE]. Sould return an exception." << std::endl;
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;
    return 0;
}