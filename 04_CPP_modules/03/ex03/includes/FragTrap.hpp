/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <mmaxime-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:32:52 by mmaxime-          #+#    #+#             */
/*   Updated: 2023/01/26 11:32:52 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "./ClapTrap.hpp"

class FragTrap : public virtual ClapTrap // avec virtual, l'appel explicite au constructeur de ClapTrap est ignoré
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