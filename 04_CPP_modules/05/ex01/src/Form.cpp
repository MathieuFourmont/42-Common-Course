/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 18:02:05 by mmaxime-          #+#    #+#             */
/*   Updated: 2023/02/03 18:02:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"

// CONSTRUCTORS AND DESTRUCTOR

Form::Form() : _name( "Unamed form" ), _formStatus( false ), _gradeS( 150 ), _gradeX( 150 )
{
	return ;
}

Form::Form( std::string const name, int const gradeS, int const gradeX ) : _name( name ), _formStatus( false ), _gradeS( gradeS ), _gradeX( gradeX )
{
	if ( _gradeS > 150 || _gradeX > 150 )
		throw( Form::GradeTooLowException() );
	else if ( _gradeS < 1 || _gradeX < 1 )
		throw( Form::GradeTooHightException() );
	return ;
}

Form::Form( Form const & src ) : _name( src._name ), _formStatus( false ), _gradeS( src._gradeS ), _gradeX( src._gradeX )
{
	if ( _gradeS > 150 || _gradeX > 150 )
		throw( Form::GradeTooLowException() );
	else if ( _gradeS < 1 || _gradeX < 1 )
		throw( Form::GradeTooHightException() );
	return ;
}

Form::~Form()
{
	return ;
}

// OVERLOADS //

Form &	Form::operator=( Form const & rhs )
{
	if ( this != &rhs )
		(void) rhs;
	return ( *this );
}

std::ostream &	operator<<( std::ostream & o, Form const & rhs )
{
	o << "Form: " << rhs.getName() \
	<< ", grade to sign = " << rhs.getGradeS() << ", grade to execute = " << rhs.getGradeX() \
	<< ( rhs.getStatus() ? " is signed." : " is not signed." );
	return ( o );
}

// ACCESSORS //

std::string const &	Form::getName() const
{
	return ( _name );
}

bool	Form::getStatus() const
{
	return ( _formStatus );
}

int const &	Form::getGradeS() const
{
	return ( _gradeS );
}

int const &	Form::getGradeX() const
{
	return ( _gradeX );
}

// MEMBER FUNCTIONS //

void	Form::beSigned( Bureaucrat & bureaucrat )
{
	if ( bureaucrat.getGrade() > _gradeS )
		throw( Bureaucrat::GradeTooLowException() );
	else
		_formStatus = true;
	return ;
}

// EXCEPTIONS //

const char*	Form::GradeTooHightException::what() const throw()
{
	return ( "Grade too high!" );
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return ( "Grade to low..." );
}