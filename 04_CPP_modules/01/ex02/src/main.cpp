/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <mmaxime-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:13:40 by mmaxime-          #+#    #+#             */
/*   Updated: 2023/01/26 11:13:40 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <iomanip>

int main()
{
	std::string		str = "HI THIS IS BRAIN";
	std::string*	stringPTR = &str;
	std::string&	stringREF = str;

	std::cout << "ADRESSES:" << std::endl;
	std::cout << "str: " << &str << std::endl;
	std::cout << "ptr: " << stringPTR << std::endl;
	std::cout << "ref: " << &stringREF << std::endl;
	
	std::cout << "VALEURS:" << std::endl;
	std::cout << "str: " << str << std::endl;
	std::cout << "ptr: " << *stringPTR << std::endl;
	std::cout << "ref: " << stringREF << std::endl;
	return (0);
}