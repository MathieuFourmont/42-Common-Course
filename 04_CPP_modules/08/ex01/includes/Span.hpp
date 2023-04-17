/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <mmaxime-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:53:14 by mmaxime-          #+#    #+#             */
/*   Updated: 2023/04/17 12:07:54 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_H
# define SPAN_H

#include <vector>
#include <algorithm>
#include <iostream>
#include <exception>
#include <limits>
#include <ctime>
#include <cstdlib>

class Span
{
	public:
		Span();
		Span( unsigned int n );
		Span( Span const & src );
		~Span();

		Span &				operator=( Span const & rhs );

		void				addNumber( int nb );
		unsigned int		shortestSpan() const;
		unsigned int		longestSpan() const;
		void				fillRandom();
		void				printSpan();

	private:
		std::vector<int>	_span;
};

#endif