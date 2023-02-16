/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <mmaxime-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 15:51:29 by mmaxime-          #+#    #+#             */
/*   Updated: 2023/02/13 16:11:12 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
# define ARRAY_H

#include <iostream>
#include <exception>
#include <ctime>
#include <cstdlib>

template < typename T >	
class Array
{
	public:
		Array() : _array( new T[0] ), _size( 0 )
		{
			return ;
		}

		Array( unsigned int n ) : _array( new T[n] ), _size ( n )
		{
			return ;
		}

		Array( Array const & src) : _array ( new T[src._size] ), _size( src._size )
		{
			for ( size_t i = 0; i < _size; i++ )
				_array[i] = src._array[i];
			return ;
		}

		~Array()
		{
			delete[] _array;
			return ;
		}

		Array &			operator=( Array const & rhs )
		{
			if ( this != &rhs )
			{
				delete[] _array;
				_array = new T[rhs._size];
				_size = rhs._size;
				for ( size_t i = 0; i < _size; i++ )
					_array[i] = rhs._array[i];
			}
			return ( *this );
		}

		T &				operator[]( unsigned int i )
		{
			if ( i >= _size )
				throw( std::out_of_range("Array index out of bounds" ) );
			return ( _array[i] );
		}

		const T &		operator[]( unsigned int i ) const
		{
			if ( i >= _size )
				throw( std::out_of_range("Array index out of bounds" ) );
			return ( _array[i] );
		}

		unsigned int	size() const
		{
			return ( _size );
		}
	
	private:
		T*				_array;
		unsigned int	_size;
		
};

// For testing purposes //
template < typename T > void	printArray( Array<T>& array, unsigned int len )
{
	for ( size_t i = 0; i < len; i++ )
		std::cout << array[i] << " ";
	return ;
}

template < typename T > void	printTypeArray( T& array, unsigned int len )
{
	for ( size_t i = 0; i < len; i++ )
		std::cout << array[i] << " ";
	return ;
}

#endif