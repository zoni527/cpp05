/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 16:06:15 by jvarila           #+#    #+#             */
/*   Updated: 2025/09/08 16:21:54 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
public:
	ShrubberyCreationForm( void );
	ShrubberyCreationForm( ShrubberyCreationForm const &other );
	ShrubberyCreationForm( std::string const &name, unsigned int gradeToSign );
	~ShrubberyCreationForm( void ) = default;

	ShrubberyCreationForm	&operator=( ShrubberyCreationForm const &rhs ) = delete;

	virtual void	beSigned( Bureaucrat const &b ) override;

	static constexpr unsigned int	SIGN_GRADE = 145;
	static constexpr unsigned int	EXEC_GRADE = 137;
};
