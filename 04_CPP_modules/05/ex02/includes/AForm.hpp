/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 18:01:15 by mmaxime-          #+#    #+#             */
/*   Updated: 2023/02/03 18:01:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_H
# define AFORM_H

#include <iostream>
#include <string>
#include <stdexcept>
class AForm;
#include "Bureaucrat.hpp"

class AForm
{
	public:
		AForm();
		AForm( std::string const name, std::string const target, int const gradeS, int const gradeX );
		AForm( AForm const & src );
		virtual	~AForm();

		AForm &				operator=( AForm const & rhs );

		std::string const &	getName() const;
		std::string const &	getTarget() const;
		bool				getStatus() const;
		int const &			getGradeS() const;
		int const &			getGradeX() const;
		void				beSigned( Bureaucrat & bureaucrat );
		virtual void		executeSpecForm() const = 0;
		void				execute( Bureaucrat const & executor );

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

		class FormNotSignedException : public std::exception
		{
			public:
				const char*	what() const throw();
		};

	private:
		std::string const	_name;
		std::string const	_target;
		bool				_formStatus;
		int const			_gradeS;
		int const			_gradeX;
};

std::ostream &	operator<<( std::ostream & o, AForm const & rhs );

#endif