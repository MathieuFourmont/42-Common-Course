/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:56:38 by mmaxime-          #+#    #+#             */
/*   Updated: 2022/11/02 14:56:38 by marvin           ###   ########.fr       */
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
		void	(Harl::*f[4]) ( void );
		void	debug( void );
		void	info( void );
		void	warning( void );
		void	error( void );
};

# endif