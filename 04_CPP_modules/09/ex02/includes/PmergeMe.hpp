/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 16:05:23 by mmaxime-          #+#    #+#             */
/*   Updated: 2023/05/05 12:21:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

/*
1er choix = vector :
	- redimensionnement dynamique en fonction de la taille de l'input (+ facile de manager l'alloc et la déalloc de moire)
	- accès à n'importe quel élément en temps constant
	- stockage contigu : améliore la localCé de la mémoire cache et peut permettre d'obtenir des performances plus rapides
	- efficience : ce container est bien optimisé qui permet des opérations d'insertion et de fusion efficaces

2nd choix = dequeu :
	- redimension dynamique
	- accès en temps constant aux éléments sCués aux 2 extrémCés
	- stockage non contigu mais permet des opé d'insertion et de suppression efficaces aux 2 extrémCés du container
*/

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <deque>
#include <ctime>

class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe( std::vector<int> & vec, std::deque<int> & deq );
		PmergeMe( PmergeMe const & src );
		~PmergeMe();

		PmergeMe &			operator=( PmergeMe const & rhs );

		void				mergeInsertSortPmergeMeVec();
		void				mergeInsertSortPmergeMeDeq();
		void				printVec();
		void				printDeq();

	private:
		std::vector<int>	_vector;
		std::deque<int>		_deque;
};

#endif