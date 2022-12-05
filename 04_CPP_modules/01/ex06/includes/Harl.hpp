/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 19:33:28 by mmaxime-          #+#    #+#             */
/*   Updated: 2022/11/02 19:33:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <string>

class Harl
{
	public:
		Harl();
		~Harl();

		void	complain( std::string level );

	private:
		void	debug( void );
		void	info( void );
		void	warning( void );
		void	error( void );

		std::string	_array[4];
};

# endif