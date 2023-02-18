/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <mmaxime-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:58:16 by mmaxime-          #+#    #+#             */
/*   Updated: 2023/02/18 13:53:22 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"

int main()
{
	// // Empty vector
	// Span sp0 = Span();

	// std::cout << std::endl << "	***Testing with an empty vector***" << std::endl;
	// std::cout << "Span vector 0: ";
	// sp0.printSpan();
	// std::cout << std::endl;
	// std::cout << "Sould throw 2 exception:" << std::endl;
	// try
	// {
	// 	std::cout << "The shortest span is: " << sp0.shortestSpan() << std::endl;
	// 	std::cout << std::endl;
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
	// try
	// {
	// 	std::cout << "The longest span is: " << sp0.longestSpan() << std::endl;
	// 	std::cout << std::endl;
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
	// std::cout << std::endl;
	// Negative values
	// Span sp1 = Span(5);

	// sp1.addNumber(6);
	// sp1.addNumber(3);
	// sp1.addNumber(-2222222);
	// sp1.addNumber(-9);
	// sp1.addNumber(11);

	// std::cout << std::endl << "	***Testing with negative values***" << std::endl;
	// std::cout << "Span vector 1: ";
	// sp1.printSpan();
	// std::cout << std::endl;
	// try
	// {
	// 	std::cout << "The shortest span is: " << sp1.shortestSpan() << std::endl;
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << std::endl;
	// }
	// try
	// {
	// 	std::cout << "The longest span is: " << sp1.longestSpan() << std::endl;
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << std::endl;
	// }
	// std::cout << std::endl;

	// Too many elements
	// Span sp2 = Span(5);

	// std::cout << std::endl << "	***Testing with too many elements***" << std::endl;

	// std::cout << "Adding 1rst number: 14" << std::endl;
	// sp2.addNumber(14);
	// std::cout << "Adding 2nd number: 120" << std::endl;
	// sp2.addNumber(120);
	// std::cout << "Adding 3rd number: 1" << std::endl;
	// sp2.addNumber(1);
	// std::cout << "Adding 4th number: 4" << std::endl;
	// sp2.addNumber(4);
	// std::cout << "Adding 5th number: 30" << std::endl;
	// sp2.addNumber(30);
	// std::cout << "Adding 6th number: 52 /* Should return an exception */" << std::endl;
	// sp2.addNumber(52);
	// std::cout << std::endl;
	// std::cout << "Span vector 2: ";
	// sp2.printSpan();
	// std::cout << std::endl;
	// try
	// {
	// 	std::cout << "The shortest span is: " << sp2.shortestSpan() << std::endl;
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << std::endl;
	// }
	// try
	// {
	// 	std::cout << "The longest span is: " << sp2.longestSpan() << std::endl;
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << std::endl;
	// }
	// std::cout << std::endl;

	// Normal behavior:
	// Span sp3 = Span(5);

	// sp3.addNumber(6);
	// sp3.addNumber(3);
	// sp3.addNumber(17);
	// sp3.addNumber(9);
	// sp3.addNumber(11);

	// std::cout << "	***Testing the normal behavior***" << std::endl;
	// std::cout << "Span vector 3: ";
	// sp3.printSpan();
	// std::cout << std::endl;
	// try
	// {
	// 	std::cout << "The shortest span is: " << sp3.shortestSpan() << std::endl;
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << std::endl;
	// }
	// try
	// {
	// 	std::cout << "The longest span is: " << sp3.longestSpan() << std::endl;
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << std::endl;
	// }
	// std::cout << std::endl;

	// Normal behavior large amount of elements:
	Span sp4 = Span(1000);

	
	srand(10);
	sp4.fillRandom();

	std::cout << "	***Testing the normal behavior with a large amount of elements***" << std::endl;
	std::cout << "Span vector 4: ";
	sp4.printSpan();
	std::cout << std::endl;
	try
	{
		std::cout << "The shortest span is: " << sp4.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << "The longest span is: " << sp4.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	exit(0);

	return( 0 );
}