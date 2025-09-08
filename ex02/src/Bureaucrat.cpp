/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 14:31:12 by jvarila           #+#    #+#             */
/*   Updated: 2025/09/08 16:16:49 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>

Bureaucrat::Bureaucrat( void )
	: _name( Bureaucrat::_default_name ),
	_grade( Bureaucrat::_default_grade ) {}

Bureaucrat::Bureaucrat(std::string const &name, unsigned int grade)
	: _name( name ), _grade( grade )
{
	if ( _grade > 150 )
		throw GradeTooLowException();
	else if ( _grade < 1 )
		throw GradeTooHighException();
}

Bureaucrat::Bureaucrat( Bureaucrat const &other )
	: _name( other._name ), _grade( other._grade ) {}

/* -------------------------------------------------------------------------- */

std::string const	&Bureaucrat:: getName( void ) const
{
	return _name;
}

unsigned int		Bureaucrat:: getGrade( void ) const
{
	return _grade;
}

void				Bureaucrat:: incrementGrade( void )
{
	--_grade;
	if ( _grade < 1 )
		throw GradeTooHighException();
}

void				Bureaucrat:: decrementGrade( void )
{
	++_grade;
	if ( _grade > 150 )
		throw GradeTooHighException();
}

void				Bureaucrat:: signForm( AForm &f ) const
{
	try
	{
		f.beSigned( *this );
		std::cout << _name << " signed " << f.getName() << std::endl;
	}
	catch( std::exception &e )
	{
		std::cout
			<< _name << " couldn't sign " << f.getName()
			<< " because " << _name << "'s grade is " << getGrade()
			<< " and the grade required to sign " << f.getName()
			<< " is " << f.getGradeToSign() << "." << std::endl;
	}
}

/* -------------------------------------------------------------------------- */

std::ostream	&operator<<( std::ostream &os, Bureaucrat const &b )
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << "." << std::endl;
	return os;
}

/* -------------------------------------------------------------------------- */

const char	*Bureaucrat::GradeTooLowException::what( void ) const noexcept
{
	return "Bureaucrat's grade is too low";
}

const char	*Bureaucrat::GradeTooHighException::what( void ) const noexcept
{
	return "Bureaucrat's grade is too high";
}
