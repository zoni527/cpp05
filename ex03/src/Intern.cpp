/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 12:58:15 by jvarila           #+#    #+#             */
/*   Updated: 2025/09/10 13:51:06 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <map>
#include <iostream>

enum FormType : int
{
	UNKNOWN = 0,
	SHRUB,
	ROBO,
	PREZ,
};

const std::map<std::string, FormType>	forms =
{
	{ "shrubbery creation", SHRUB },
	{ "robotomy request", ROBO },
	{ "presidential pardon", PREZ },
};

AForm	*Intern:: makeForm( std::string const &formName, std::string const &target ) const
{
	FormType	type = UNKNOWN;
	auto		typePtr = forms.find( formName );
	if ( typePtr != forms.end() )
	{
		type = typePtr->second;
		std::cout << "(unpaid) intern creates " << formName << " form" << std::endl;
	}
	switch( type )
	{
		case SHRUB:
			return new ShrubberyCreationForm( target );
		case ROBO:
			return new RobotomyRequestForm( target );
		case PREZ:
			return new PresidentialPardonForm( target );
		default:
			std::string	msg = formName + " form is not known to the (unpaid) intern";
			std::cout << msg << std::endl;
			throw std::invalid_argument( msg );
	}
}
