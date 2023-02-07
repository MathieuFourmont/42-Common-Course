/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 18:01:15 by mmaxime-          #+#    #+#             */
/*   Updated: 2023/02/03 18:01:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
# define FORM_H

#include <iostream>
#include <string>
#include <stdexcept>
class Form;
#include "Bureaucrat.hpp"

class Form
{
	public:
		Form();
		Form( std::string const name, int const gradeS, int const gradeX );
		Form( Form const & src );
		~Form();

		Form &				operator=( Form const & rhs );

		std::string const &	getName() const;
		bool				getStatus() const;
		int const &			getGradeS() const;
		int const &			getGradeX() const;
		void				beSigned( Bureaucrat & bureaucrat );

		class GradeTooHightException : public std::exception
		{
			public:
				const char*	what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char*	what() const throw();
		};

	private:
		std::string const	_name;
		bool				_formStatus;
		int const			_gradeS;
		int const			_gradeX;
};

std::ostream &	operator<<( std::ostream & o, Form const & rhs );

#endif