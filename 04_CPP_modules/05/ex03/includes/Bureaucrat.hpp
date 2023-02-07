/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:25:11 by mmaxime-          #+#    #+#             */
/*   Updated: 2023/02/03 15:25:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

#include <iostream>
#include <string>
#include <stdexcept>
class Bureaucrat;
#include "AForm.hpp"

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat( std::string const name, int grade );
		Bureaucrat( Bureaucrat const & src );
		~Bureaucrat();

		Bureaucrat &		operator=( Bureaucrat const & rhs );

		std::string const &	getName() const;
		int					getGrade() const;
		void				increaseGrade();
		void				decreaseGrade();
		void				signForm( AForm & form );
		void				executeForm( AForm & form);

		class GradeTooHightException : public std::exception // définition d'une custom exception par héritage
		{
			public:
				const char*	what() const throw(); // renvoie une chaine de char (via what()) contenant des infos sur l'erreur (via throw())
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char*	what() const throw();
		};

	private:
		std::string			_name;
		int					_grade;
};

std::ostream &	operator<<( std::ostream & o, Bureaucrat const & rhs);

#endif