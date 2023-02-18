/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <mmaxime-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:08:26 by mmaxime-          #+#    #+#             */
/*   Updated: 2023/02/18 13:53:38 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"

// CONSTRUCTORS & DESTRUCTOR //

Span::Span() : _span( std::vector<int>() )
{
	_span.reserve( 0 );
	return ;
}

Span::Span( unsigned int n ) : _span( std::vector<int>() )
{
	_span.reserve( n );
	return ;
}

Span::Span( Span const & src ) : _span( std::vector<int>( src._span ) )
{
	return ;
}

Span::~Span()
{
	return ;
}

// OVERLOADS //

Span &	Span::operator=( Span const & rhs )
{
	if ( this != &rhs )
		_span = std::vector<int>( rhs._span );
	return ( *this );
}

// MEMBER FUNCTIONS //

void	Span::addNumber( int nb )
{
	try
	{
		if ( _span.capacity() == _span.size() )
			throw ( std::out_of_range( "Vector is full!" ) );
		else
			_span.push_back( nb );
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}	
	return ;
}

unsigned int	Span::shortestSpan() const
{
	if ( _span.size() < 2 )
		throw ( std::out_of_range( "Not enough elements..." ) );
	
	std::vector<int>	tmp( _span );
	unsigned int		res = std::numeric_limits<unsigned int>::max();
	unsigned int		diff;

	std::sort( tmp.begin(), tmp.end() );
	for ( size_t i = 1; i < _span.size(); i++ )
	{
		diff = tmp[i] - tmp[i - 1];
		res = ( diff < res ) ? diff : res;
	}
	return ( res );
}

unsigned int	Span::longestSpan() const
{
	if ( _span.size() < 2 )
		throw ( std::out_of_range( "Not enough elements..." ) );
	
	unsigned int	max = *std::max_element( _span.begin(), _span.end() );
	unsigned int	min = *std::min_element( _span.begin(), _span.end() );
	return ( max - min );
}

void	Span::fillRandom()
{
	_span.assign( _span.capacity(), 0 );
	// srand( time( NULL ) );
	std::generate( _span.begin(), _span.end(), std::rand );
}

void	Span::printSpan()
{
	std::vector<int>::const_iterator	it;

	for ( it = _span.begin(); it != _span.end(); ++it )
		std::cout << *it << " ";
}