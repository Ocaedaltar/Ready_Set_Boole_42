/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 20:29:26 by mlormois          #+#    #+#             */
/*   Updated: 2022/03/15 02:11:07 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Conjonctive.hpp"

std::string conjunctive_normal_form( std::string const & formula )
{
	is_rpn( formula );
	ft::Ast tree( formula );
	tree.conjonctive_form();
	return tree.to_string();
}

int main( int ac, char **av )
{
	if ( ac != 2)
		return 1;

	try
	{

		std::cout << "AB&!" << ": " << conjunctive_normal_form( "AB&!" ) << std::endl;
		std::cout << "AB|!" << ": " << conjunctive_normal_form( "AB|!" ) << std::endl;
		std::cout << "AB|C&" << ": " << conjunctive_normal_form( "AB|C&" ) << std::endl;
		std::cout << "AB|C|D|" << ": " << conjunctive_normal_form( "AB|C|D|" ) << std::endl;
		std::cout << "AB&C&D&" << ": " << conjunctive_normal_form( "AB&C&D&" ) << std::endl;
		std::cout << "AB&!C!|" << ": " << conjunctive_normal_form( "AB&!C!|" ) << std::endl;
		std::cout << "AB|!C!&" << ": " << conjunctive_normal_form( "AB|!C!&" ) << std::endl;
		std::cout << "complex:" << std::endl << "AB&CD&&AB|CD||&" << ": " << conjunctive_normal_form( "AB&CD&&AB|CD||&" ) << std::endl;
		std::cout << "your:" << std::endl << conjunctive_normal_form( av[1] ) << std::endl;
	}
	catch(const std::invalid_argument& ia)
	{
		std::cerr << "Invalide Argument: \"" << av[1] << "\" " << ia.what() << std::endl;
		return 1;
	}
	return (0);
}