/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 18:14:49 by mmaxime-          #+#    #+#             */
/*   Updated: 2023/04/07 18:14:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"

RPN::RPN()
{
	return ;
}

RPN::RPN( std::string operation ) : _ope( operation )
{
	return ;
}

RPN::RPN( RPN const & src ) : _ope( src._ope )
{
	return ;
}

RPN::~RPN()
{
	return ;
}

RPN &	RPN::operator=( RPN const & rhs )
{
	if ( this != &rhs )
		_ope = rhs._ope;
	return ( *this );
}

bool	checkRes( double res )
{
	if ( res > INT_MAX || res <= INT_MIN )
		return ( false );
	return ( true );
}

void	RPN::calculation()
{
	std::stack<double>	RPNStack;
	double				leftNb;
	double				rightNb;
	std::stringstream	ss( _ope );
	std::string			token;
	int					res;

	while ( std::getline( ss, token, ' ' ))
	{
		if ( token == "+" || token == "-" || token == "*" || token == "/" )
		{
			if ( RPNStack.size() < 2 )
				throw std::length_error( "Error: at least one nb is missing to perform this calculation" );
			rightNb = RPNStack.top();
			RPNStack.pop();
			leftNb = RPNStack.top();
			RPNStack.pop();
			if ( token == "+" )
				res = leftNb + rightNb;
			else if ( token == "-" )
				res = leftNb - rightNb;
			else if ( token == "*" )
				res = leftNb * rightNb;
			else
				res = leftNb / rightNb;
			RPNStack.push( res );
		}
		else if ( std::isdigit( token[0] ) && ( std::atof( token.c_str() ) < 10 ) )
			RPNStack.push( std::atof( token.c_str() ) );
		else
			throw std::invalid_argument( "Error" );
	}
	if ( RPNStack.size() == 1)
	{
		if ( checkRes( RPNStack.top() ) == false )
			throw std::overflow_error( "Error: integer overflow");
		else
		{
			res = RPNStack.top();
			std::cout << "Result: " << res << std::endl;
		}
	}
	else
		throw std::length_error( "Error: Non-empty stack" );
}