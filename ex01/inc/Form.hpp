/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 18:05:56 by jvarila           #+#    #+#             */
/*   Updated: 2025/09/03 18:17:13 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <exception>

class Form
{
public:
	Form( void );
	Form( Form const &other );
	~Form( void ) = default;

	Form &operator=( Form const &rhs ) = delete;

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
	bool				_signed = false;
	unsigned int const	_gradeToSign;
}
