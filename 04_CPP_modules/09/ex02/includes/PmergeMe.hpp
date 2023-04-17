/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <mmaxime-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 16:05:23 by mmaxime-          #+#    #+#             */
/*   Updated: 2023/04/17 16:05:24 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <exception>
#include <string>
#include <vector>
#include <deque>

class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe( std::vector<int> vec, std::deque<int> deq );
		PmergeMe( PmergeMe const & src );
		~PmergeMe();

		PmergeMe &			operator=( PmergeMe const & rhs );

		void				printVector( PmergeMe vec );
		void				printDeque( PmergeMe deq );

	private:
		std::vector<int>	_vector;
		std::deque<int>		_deque;
};


#endif