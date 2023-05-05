/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 16:05:34 by mmaxime-          #+#    #+#             */
/*   Updated: 2023/05/05 11:57:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	return ;
}

PmergeMe::PmergeMe( std::vector<int> & vec, std::deque<int> & deq ) : _vector( vec ), _deque( deq )
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

void	mergeVec( std::vector<int> & vector, int left, int mid, int right )
{
	// fusion des 2 tableaux triés
	// partie gauche = vector[left ... mid] et partie droite = vector[mid + 1 ... right]
	int					i;
	int					j;
	int					k;

	std::vector<int>	tmp( right - left + 1 );
	i = left;		// index du 1er élément de la partie gauche
	j = mid + 1;	// index du 1er élément de la partie droite
	k = 0;			// index du 1er élément de tmp

	// fusion des parties gauche et droite
	while ( i <= mid && j <= right )
	{
		if ( vector[i] < vector[j] )
		{
			tmp[k] = vector[i];
			k++;
			i++;
		}
		else
		{
			tmp[k] = vector[j];
			k++;
			j++;
		}
	}

	// copie des éléments restants de la partie gauche
	while ( i <= mid )
	{
		tmp[k] = vector[i];
		k++;
		i++;
	}

	// copie des éléments restants de la partie droite
	while ( j <= right )
	{
		tmp[k] = vector[j];
		k++;
		j++;
	}

	// copie du vector temporaire dans l'original
	for ( i = left; i <= right; ++i )
		vector[i] = tmp[i - left];
}

void	insertionSortVec( std::vector<int> & vector, int left, int right )
{
	int	i;
	int	j;
	int	tmp;
	
	for ( i = left + 1; i <= right; ++i )
	{
		tmp = vector[i];
		j = i - 1;
		while (j >= left && vector[j] > tmp )
		{
			vector[j + 1] = vector[j];
			j--;
		}
		vector[j + 1] = tmp;
	}
}

void	mergeInsertSortVec( std::vector<int> & vector, int left, int right )
{
	int	mid;

	if ( left < right )
	{
		mid = ( left + right ) / 2;
		if ( right - left < 32 )
			insertionSortVec( vector, left, right );
		else
		{
			mergeInsertSortVec( vector, left, mid );
			mergeInsertSortVec( vector, mid + 1, right );
			mergeVec( vector, left, mid, right );
		}
	}
}

void	PmergeMe::printVec()
{
	for ( std::vector<int>::const_iterator it = _vector.begin(); it != _vector.end(); ++it )
		std::cout << *it << " ";
	std::cout << std::endl;
}

void	PmergeMe::mergeInsertSortPmergeMeVec()
{
	mergeInsertSortVec( _vector, 0, _vector.size() - 1 );
}

void	mergeDeq( std::deque<int> & deque, int left, int mid, int right )
{
	// fusion des 2 tableaux triés
	// partie gauche = vector[left ... mid] et partie droite = vector[mid + 1 ... right]
	int				i;
	int				j;
	int				k;

	std::deque<int>	tmp( right - left + 1 );
	i = left;		// index du 1er élément de la partie gauche
	j = mid + 1;	// index du 1er élément de la partie droite
	k = 0;			// index du 1er élément de tmp

	// fusion des parties gauche et droite
	while ( i <= mid && j <= right )
	{
		if ( deque[i] < deque[j] )
		{
			tmp[k] = deque[i];
			k++;
			i++;
		}
		else
		{
			tmp[k] = deque[j];
			k++;
			j++;
		}
	}

	// copie des éléments restants de la partie gauche
	while ( i <= mid )
	{
		tmp[k] = deque[i];
		k++;
		i++;
	}

	// copie des éléments restants de la partie droite
	while ( j <= right )
	{
		tmp[k] = deque[j];
		k++;
		j++;
	}

	// copie du vector temporaire dans l'original
	for ( i = left; i <= right; ++i )
		deque[i] = tmp[i - left];
}

void	insertionSortDeq( std::deque<int> & deque, int left, int right )
{
	int	i;
	int	j;
	int	tmp;
	
	for ( i = left + 1; i <= right; ++i )
	{
		tmp = deque[i];
		j = i - 1;
		while (j >= left && deque[j] > tmp )
		{
			deque[j + 1] = deque[j];
			j--;
		}
		deque[j + 1] = tmp;
	}
}

void	mergeInsertSortDeq( std::deque<int> & deque, int left, int right )
{
	int	mid;

	if ( left < right )
	{
		mid = ( left + right ) / 2;
		if ( right - left < 32 )
			insertionSortDeq( deque, left, right );
		else
		{
			mergeInsertSortDeq( deque, left, mid );
			mergeInsertSortDeq( deque, mid + 1, right );
			mergeDeq( deque, left, mid, right );
		}
	}
}

void	PmergeMe::printDeq()
{
	for ( std::deque<int>::const_iterator it = _deque.begin(); it != _deque.end(); ++it )
		std::cout << *it << " ";
	std::cout << std::endl;
}

void	PmergeMe::mergeInsertSortPmergeMeDeq()
{
	mergeInsertSortDeq( _deque, 0, _deque.size() - 1 );
}