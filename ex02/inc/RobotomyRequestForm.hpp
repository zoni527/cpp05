/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 16:13:57 by jvarila           #+#    #+#             */
/*   Updated: 2025/09/08 16:21:07 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
public:
	RobotomyRequestForm( void );
	RobotomyRequestForm( RobotomyRequestForm const &other );
	RobotomyRequestForm( std::string const &name, unsigned int gradeToSign );
	~RobotomyRequestForm( void ) = default;

	RobotomyRequestForm	&operator=( RobotomyRequestForm const &rhs ) = delete;

	virtual void	beSigned( Bureaucrat const &b ) override;

	static constexpr unsigned int	SIGN_GRADE = 72;
	static constexpr unsigned int	EXEC_GRADE = 45;
};
