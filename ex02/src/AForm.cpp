/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 13:41:04 by jvarila           #+#    #+#             */
/*   Updated: 2025/09/08 14:27:30 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm:: AForm( void )
	: _name( "Generic form"), _gradeToSign( 150 ) {}

AForm:: AForm( AForm const &other )
	:	_name( other._name ),
		_gradeToSign( other._gradeToSign ),
		_isSigned( other._isSigned ) {}

AForm:: AForm( std::string const &name, unsigned int gradeToSign )
	: _name( name ), _gradeToSign( gradeToSign )
{
	if ( _gradeToSign > 150 )
		throw GradeTooLowException();
	else if ( _gradeToSign < 1 )
		throw GradeTooHighException();
}

/* -------------------------------------------------------------------------- */

std::string const	&AForm:: getName( void ) const
{
	return _name;
}

unsigned int		AForm:: getGradeToSign( void ) const
{
	return _gradeToSign;
}

bool				AForm:: getIsSigned( void ) const
{
	return _isSigned;
}

/* -------------------------------------------------------------------------- */

std::ostream	&operator<<( std::ostream &os, AForm const &f )
{
	os	<< f.getName() << ", grade required to sign: " << f.getGradeToSign()
		<< "." << std::endl;
	return os;
}

/* -------------------------------------------------------------------------- */

const char	*AForm::GradeTooLowException::what( void ) const noexcept
{
	return "AForms's grade is too low";
}

const char	*AForm::GradeTooHighException::what( void ) const noexcept
{
	return "AForms's grade is too high";
}
