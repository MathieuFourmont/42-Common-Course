/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <mmaxime-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:01:49 by mmaxime-          #+#    #+#             */
/*   Updated: 2023/04/17 12:03:41 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_H
# define MUTANTSTACK_H

#include <iostream>
#include <stack>
#include <vector>
#include <exception>

template < typename T, class Container = std::deque<T> >
class MutantStack : public std::stack<T>
{
	public:
		MutantStack()
		{
			return ;
		}
		MutantStack( MutantStack const & src )
		{
			*this = src;
			return ;
		}
		~MutantStack()
		{
			return ;
		}

		MutantStack &	operator=( MutantStack const & rhs )
		{
			if ( this != &rhs )
				this->c = rhs.c; // c = type du container sous-jacent de la stack (ici dequeue), permet donc d'acceder aux membres de celui-ci 
			return ( *this );
		}

		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator		begin()
		{
			return ( this->c.begin() );
		}
		iterator		end()
		{
			return ( this->c.end() );
		}
};

#endif