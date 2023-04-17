/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 18:13:59 by mmaxime-          #+#    #+#             */
/*   Updated: 2023/04/07 18:13:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <stack>
#include <string>
#include <iostream>
#include <sstream>
#include <exception>
#include <cstdlib>
#include <climits>

class RPN
{
	public:
		RPN();
		RPN( std::string const operation );
		RPN( RPN const & src );
		~RPN();

		RPN &		operator=( RPN const & rhs );

		void		calculation();

	private:
		std::string	_ope;
		// int		_RPNResult;
};

#endif