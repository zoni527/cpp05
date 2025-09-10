/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 14:24:44 by jvarila           #+#    #+#             */
/*   Updated: 2025/09/08 14:14:30 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <ostream>
#include <string>
#include <exception>

class Form;

class Bureaucrat
{
public:
	Bureaucrat( void );
	Bureaucrat( Bureaucrat const &other );
	Bureaucrat( std::string const &_name, unsigned int grade );
	~Bureaucrat( void ) = default;

	Bureaucrat	&operator=( Bureaucrat const &other ) = delete;

	std::string const	&getName( void ) const;
	unsigned int		getGrade( void ) const;

	void				incrementGrade( void );
	void				decrementGrade( void );

	void				signForm( Form &f ) const;

private:
	std::string const	_name;
	unsigned int		_grade;

	static constexpr char const		*DEFAULT_NAME	= "Default Dave";
	static constexpr unsigned int	DEFAULT_GRADE	= 150;

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
};

std::ostream	&operator<<( std::ostream &os, Bureaucrat const &b );
