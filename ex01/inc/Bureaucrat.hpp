/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 14:24:44 by jvarila           #+#    #+#             */
/*   Updated: 2025/09/03 14:55:29 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <ostream>
#include <string>
#include <exception>

class Bureaucrat
{
public:
	Bureaucrat( void );
	Bureaucrat( Bureaucrat const &other );
	Bureaucrat( std::string const &_name, unsigned int grade );
	~Bureaucrat( void ) = default;

	Bureaucrat	&operator=( Bureaucrat const &other ) = delete;

	std::string		getName( void ) const;
	unsigned int	getGrade( void ) const;

	void			incrementGrade( void );
	void			decrementGrade( void );

private:
	std::string const	_name;
	unsigned int		_grade;

	static constexpr char const		*_default_name	= "Default Dave";
	static constexpr unsigned int	_default_grade	= 150;

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

std::ostream	&operator<<(std::ostream &os, Bureaucrat const &b);
