/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <mmaxime-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:03:10 by mmaxime-          #+#    #+#             */
/*   Updated: 2023/04/17 12:03:24 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MutantStack.hpp"
#include <iostream>
#include <sstream>
#include <list>

static void test_subject(void) {
	std::cout << "*** Test Subject ***" << std::endl;

	MutantStack<int> mstack;

	std::cout << "Adding 5" << std::endl;
	mstack.push(5);
	std::cout << "Adding 17" << std::endl;
	mstack.push(17);

	std::cout << "Top: " << mstack.top() << std::endl;

	mstack.pop(); // supprime l'element au top de la stack

	std::cout << "Size after pop: " << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	std::cout << "Test to increment and to decrement: initial pos: " << *it << std::endl;
	++it;
 	std::cout << "pos after increment: " << *it << std::endl;
	--it;
	std::cout << "pos after decrement: " << *it << std::endl;
	std::cout << "Print of the whole stack:" << std::endl;
	while ( it != ite )
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::stack<int> s(mstack);

	std::cout << std::endl;
}

static void test_10_numbers(void) {
	std::cout << "*** Test 10 Numbers ***" << std::endl;

	MutantStack<int, std::vector<int> > mstack;

	for (int i = 0; i < 10; i++)
	{
		mstack.push(i);
	}

	std::cout << "Top: " << mstack.top() << std::endl; // accede a l'element au top de la stack
	std::cout << "Size: " << mstack.size() << std::endl;

	for ( MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it )
	{
		std::cout << *it << std::endl;
	}

	// Test copie profonde
	std::stack<int> s(mstack);

	std::cout << std::endl;
}

static void test_10_strings(void) {
	std::cout << "*** Test 10 Strings ***" << std::endl;

	MutantStack<std::string> mstack;

	// on ajoute ici tous les nb en strings (stream conversion)
	for (int i = 0; i < 10; i++) {
		std::ostringstream ss;
		ss << i;
		mstack.push(ss.str()); 
	}

	std::cout << "Top: " << mstack.top() << std::endl;
	std::cout << "Size: " << mstack.size() << std::endl;

	for (MutantStack<std::string>::iterator it = mstack.begin(); 
									it != mstack.end(); 
									it++) {
		std::cout << *it << std::endl;
	}

	// Test copie profonde
	std::stack<std::string> s(mstack);

	std::cout << std::endl;
}

static void test_10_lists(void) {
	std::cout << "*** Test 10 Lists ***" << std::endl
				<< "/* For comparison */" << std::endl;

	std::list<int> lstack;

	for (int i = 0; i < 10; i++) {
		lstack.push_back(i); 
	}

	std::cout << "Top: " << lstack.back() << std::endl;
	std::cout << "Size: " << lstack.size() << std::endl;

	for (std::list<int>::iterator it = lstack.begin(); 
									it != lstack.end(); 
									it++) {
		std::cout << *it << std::endl;
	}

	// Test copie profonde
	std::list<int> s(lstack);

	std::cout << std::endl;
}

int main(void) {
	test_subject();
	test_10_numbers();
	test_10_strings();
	test_10_lists();
}