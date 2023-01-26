/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <mmaxime-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:22:23 by mmaxime-          #+#    #+#             */
/*   Updated: 2023/01/26 11:22:23 by mmaxime-         ###   ########.fr       */
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