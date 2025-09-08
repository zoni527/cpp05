/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 16:27:29 by jvarila           #+#    #+#             */
/*   Updated: 2025/09/08 16:27:42 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
public:
	PresidentialPardonForm( void );
	PresidentialPardonForm( PresidentialPardonForm const &other );
	PresidentialPardonForm( std::string const &name, unsigned int gradeToSign );
	~PresidentialPardonForm( void ) = default;

	PresidentialPardonForm	&operator=( PresidentialPardonForm const &rhs ) = delete;

	virtual void	beSigned( Bureaucrat const &b ) override;

	static constexpr unsigned int	SIGN_GRADE = 25;
	static constexpr unsigned int	EXEC_GRADE = 5;
};
