/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:01:49 by mmaxime-          #+#    #+#             */
/*   Updated: 2023/04/05 10:54:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_H
# define MUTANTSTACK_H

#include <iostream>
#include <stack>
#include <vector>
#include <exception>

/*
	Une stack est un adaptateur de container, c-à-d qu'elle a une interface plus petite
	qu'un container pour une utilisation + facile. C'est un "container" qui n'autorise
	l'accès qu'au dernier élément ajouté.
	Un adaptateur de container est une classe qui sert d'enveloppe au conteur sous-jacent.
	Elle utilise un objet encapsulé d'une classe de container spécifique en tant que
	container sous-jacent, fournissant un ensemble spécifique de fonctions membres
	pour accéder à ses éléments.
	Une stack ne peut pas appliquer les algos définis dans la bibliothèque STL car elle
	manque d'itérateurs ; elle ne fournit pas les fonctions membres, telles que begin et end,
	pour créer des itérateurs.
	C'est pourquoi, à l'aide d'un template, nous allons définir le container_type de la stack (membre privé)
	en deque. Par ce biais, nous pourrons utiliser toutes les fonctions et attribut d'une deque, dont les itérateurs  
*/

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