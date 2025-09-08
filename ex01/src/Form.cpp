/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 13:41:04 by jvarila           #+#    #+#             */
/*   Updated: 2025/09/08 14:27:30 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form:: Form( void )
	: _name( "Generic form"), _gradeToSign( 150 ) {}

Form:: Form( Form const &other )
	:	_name( other._name ),
		_gradeToSign( other._gradeToSign ),
		_isSigned( other._isSigned ) {}

Form:: Form( std::string const &name, unsigned int gradeToSign )
	: _name( name ), _gradeToSign( gradeToSign )
{
	if ( _gradeToSign > 150 )
		throw GradeTooLowException();
	else if ( _gradeToSign < 1 )
		throw GradeTooHighException();
}

/* -------------------------------------------------------------------------- */

std::string const	&Form:: getName( void ) const
{
	return _name;
}

unsigned int		Form:: getGradeToSign( void ) const
{
	return _gradeToSign;
}

bool				Form:: getIsSigned( void ) const
{
	return _isSigned;
}

void				Form:: beSigned( Bureaucrat const &b )
{
	if ( b.getGrade() > _gradeToSign )
		throw GradeTooLowException();
	_isSigned = true;
}

/* -------------------------------------------------------------------------- */

std::ostream	&operator<<( std::ostream &os, Form const &f )
{
	os	<< f.getName() << ", grade required to sign: " << f.getGradeToSign()
		<< "." << std::endl;
	return os;
}

/* -------------------------------------------------------------------------- */

const char	*Form::GradeTooLowException::what( void ) const noexcept
{
	return "Forms's grade is too low";
}

const char	*Form::GradeTooHighException::what( void ) const noexcept
{
	return "Forms's grade is too high";
}
