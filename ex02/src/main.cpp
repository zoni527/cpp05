/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 09:46:37 by jvarila           #+#    #+#             */
/*   Updated: 2025/09/08 14:36:41 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ansi_colors.hpp"

static std::string	n_chars( char c, size_t n );
static void			print_test_name( std::string str );

int main( void )
{
	print_test_name( "Parameterized constructor" );
	{
		AForm	test( "Test form", 150 );
		std::cout << test;
	}
	print_test_name( "Copy constructor" );
	{
		AForm	original( "OG", 123 );
		AForm	copy( original );
		std::cout << copy;
	}
	print_test_name( "Getters" );
	{
		AForm	f( "Test form", 123 );
		std::cout << "AForms's name:		" << f.getName() << "\n";
		std::cout << "AForms's grade:		" << f.getGradeToSign() << "\n";
		std::cout << "AForms's signed state:	" << f.getIsSigned() << "\n";
		Bureaucrat	b( "God", 1 );
		b.signForm( f );
		std::cout << "AForms's signed state:	" << f.getIsSigned() << "\n";
	}
	print_test_name( "This form is too easy to sign" );
	{
		try
		{
			AForm	f( "Too easy", 151 );
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	print_test_name( "This form is impossible to sign" );
	{
		try
		{
			AForm	f( "Impossiburu!", 0 );
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	print_test_name( "Can't get signed" );
	{
		Bureaucrat	bob( "Bob", 150 );
		AForm		f( "Sign me please", 149 );
		bob.signForm( f );
	}
	print_test_name( "Can get signed" );
	{
		Bureaucrat	bob( "Bob", 150 );
		AForm		f( "Sign me please", 149 );
		bob.signForm( f );
	}
	std::cout << std::endl;
	return 0;
}

/* -------------------------------------------------------------------------- */

static void print_test_name( std::string str ) {

	for ( char &c : str )
		c = std::toupper( c );

	size_t width = str.length() + 10;

	std::string separator = n_chars( '-', width );
	std::cout << "\n" C_HI_Y << separator << "\n";
	std::cout << "**** " << str << " ****";
	std::cout << "\n" << separator << C_RST "\n";
	std::cout << std::endl;
}

static std::string n_chars( char c, size_t n ) {
	std::string str = "";
	while ( n-- )
		str += c;
	return str;
}
