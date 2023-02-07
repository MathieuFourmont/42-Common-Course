/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:32:31 by mmaxime-          #+#    #+#             */
/*   Updated: 2023/02/03 15:32:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

// CONSTRUCTORS & DESTRUCTOR //

Bureaucrat::Bureaucrat()
{
	return ;
}

Bureaucrat::Bureaucrat( std::string const name, int grade ) : _name( name ), _grade( grade )
{
	if ( _grade > 150 )
		throw ( Bureaucrat::GradeTooLowException() ); // throw -> va remonter dans les blocs jusqu'à trouver un bloc catch où sera gérée l'exception
	else if ( _grade < 1 )
		throw ( Bureaucrat::GradeTooHightException() );
	return ;
}

Bureaucrat::Bureaucrat( Bureaucrat const & src ) : _name( src._name ), _grade( src._grade )
{
	if ( _grade > 150 )
		throw ( Bureaucrat::GradeTooLowException() );
	else if ( _grade < 1 )
		throw ( Bureaucrat::GradeTooHightException() );
	return ;
}

Bureaucrat::~Bureaucrat()
{
	return ;
}

// OVERLOADS //

Bureaucrat &	Bureaucrat::operator=( Bureaucrat const & rhs )
{
	if ( this != &rhs )
		_grade = rhs._grade;
	return ( *this );
}

std::ostream &	operator<<( std::ostream & o, Bureaucrat const & rhs )
{
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
	return ( o );
}

// ACCESSORS //

std::string const &	Bureaucrat::getName() const
{
	return ( _name );
}

int	Bureaucrat::getGrade() const
{
	return ( _grade );
}

// MEMBER FUNCTIONS //

void	Bureaucrat::increaseGrade()
{
	_grade--;
	if ( _grade < 1 )
		throw( Bureaucrat::GradeTooHightException() );
	return ;
}

void	Bureaucrat::decreaseGrade()
{
	_grade++;
	if ( _grade > 150 )
		throw( Bureaucrat::GradeTooLowException() );
	return ;
}

// EXCEPTIONS //

const char*	Bureaucrat::GradeTooHightException::what() const throw()
{
	return ( "Grade too high!" );
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ( "Grade too low..." );
}