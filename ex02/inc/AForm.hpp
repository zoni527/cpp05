/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 18:05:56 by jvarila           #+#    #+#             */
/*   Updated: 2025/09/08 16:12:10 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <ostream>
#include <string>
#include <exception>

class Bureaucrat;

class AForm
{
public:
	AForm( void );
	AForm( AForm const &other );
	AForm( std::string const &name, unsigned int gradeToSign );
	virtual ~AForm( void ) = default;

	AForm	&operator=( AForm const &rhs ) = delete;

	std::string const	&getName( void ) const;
	unsigned int		getGradeToSign( void ) const;
	bool				getIsSigned( void ) const;

	virtual void		beSigned( Bureaucrat const &b ) = 0;

	class GradeTooHighException : public std::exception
	{
	public:
		const char	*what( void ) const noexcept override;
	};

	class GradeTooLowException : public std::exception
	{
	public:
		const char	*what( void ) const noexcept override;
	};

private:
	std::string const	_name;
	unsigned int const	_gradeToSign;
	unsigned int const	_gradeToExecute;
	bool				_isSigned = false;
};

std::ostream	&operator<<( std::ostream &os, AForm const &f );
