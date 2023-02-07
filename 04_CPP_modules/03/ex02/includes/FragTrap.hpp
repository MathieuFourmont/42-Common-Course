/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <mmaxime-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:31:24 by mmaxime-          #+#    #+#             */
/*   Updated: 2023/01/26 11:31:24 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
# define FRAGTRAP_H

#include "./ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap();
		FragTrap( std::string name );
		FragTrap( FragTrap const & src );
		~FragTrap();

		FragTrap &	operator=( FragTrap const & rhs );

		void		attack( const std::string & target );
		void		highFivesGuys();
};

# endif