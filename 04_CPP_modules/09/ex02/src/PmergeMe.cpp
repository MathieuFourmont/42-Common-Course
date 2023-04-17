/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <mmaxime-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 16:05:34 by mmaxime-          #+#    #+#             */
/*   Updated: 2023/04/17 16:05:37 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	return ;
}

PmergeMe::PmergeMe( std::vector<int> vec, std::deque<int> deq ) : _vector( vec ), _deque( deq )
{
	return ;
}

PmergeMe::PmergeMe( PmergeMe const & src ) : _vector( src._vector ), _deque( src._deque )
{
	return ;
}

PmergeMe::~PmergeMe()
{
	return ;
}

PmergeMe &	PmergeMe::operator=( PmergeMe const & rhs )
{
	if ( this != &rhs )
	{
		_vector = rhs._vector;
		_deque = rhs._deque;
	}
	return ( *this );
}