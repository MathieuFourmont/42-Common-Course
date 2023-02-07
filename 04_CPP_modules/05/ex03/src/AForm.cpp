/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 18:02:05 by mmaxime-          #+#    #+#             */
/*   Updated: 2023/02/03 18:02:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"

// CONSTRUCTORS AND DESTRUCTOR

AForm::AForm() : _name( "Unamed form" ), _formStatus( false ), _gradeS( 150 ), _gradeX( 150 )
{
	return ;
}

AForm::AForm( std::string const name, std::string const target, int const gradeS, int const gradeX ) : _name( name ), _target( target ), _formStatus( false ), _gradeS( gradeS ), _gradeX( gradeX )
{
	if ( _gradeS > 150 || _gradeX > 150 )
		throw( AForm::GradeTooLowException() );
	else if ( _gradeS < 1 || _gradeX < 1 )
		throw( AForm::GradeTooHightException() );
	return ;
}

AForm::AForm( AForm const & src ) : _name( src._name ), _target( src._target ), _formStatus( false ), _gradeS( src._gradeS ), _gradeX( src._gradeX )
{
	if ( _gradeS > 150 || _gradeX > 150 )
		throw( AForm::GradeTooLowException() );
	else if ( _gradeS < 1 || _gradeX < 1 )
		throw( AForm::GradeTooHightException() );
	return ;
}

AForm::~AForm()
{
	return ;
}

// OVERLOADS //

AForm &	AForm::operator=( AForm const & rhs )
{
	if ( this != &rhs )
		(void) rhs;
	return ( *this );
}

std::ostream &	operator<<( std::ostream & o, AForm const & rhs )
{
	o << "Form: " << rhs.getName() \
	<< ", grade to sign = " << rhs.getGradeS() << ", grade to execute = " << rhs.getGradeX() \
	<< ( rhs.getStatus() ? " is signed." : " is not signed." );
	return ( o );
}

// ACCESSORS //

std::string const &	AForm::getName() const
{
	return ( _name );
}

std::string const &	AForm::getTarget() const
{
	return ( _target );
}

bool	AForm::getStatus() const
{
	return ( _formStatus );
}

int const &	AForm::getGradeS() const
{
	return ( _gradeS );
}

int const &	AForm::getGradeX() const
{
	return ( _gradeX );
}

// MEMBER FUNCTIONS //

void	AForm::beSigned( Bureaucrat & bureaucrat )
{
	if ( bureaucrat.getGrade() > _gradeS )
		throw( Bureaucrat::GradeTooLowException() );
	else
		_formStatus = true;
	return ;
}

void	AForm::execute( Bureaucrat const & executor )
{
	if ( executor.getGrade() > _gradeX )
		throw( AForm::GradeTooLowException() );
	else if ( _formStatus == false )
		throw( AForm::FormNotSignedException() );
	else
		executeSpecForm();
	return ;
}

// EXCEPTIONS //

const char*	AForm::GradeTooHightException::what() const throw()
{
	return ( "Grade too high!" );
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return ( "Grade to low..." );
}

const char*	AForm::FormNotSignedException::what() const throw()
{
	return ( "Form is not yet signed.");
}