/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:35:10 by mlormois          #+#    #+#             */
/*   Updated: 2022/03/04 01:09:57 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "negation.hpp"

std::string negation_normal_form( std::string const & formula )
{
	// Verification de la validiter de l'input.
	is_rpn( formula );
	// Transformation en Ast
	ft::Ast tree( formula );
	tree.negation_form();
	// Return de la string grace a l'arbre de substiue en NNF
	return ( tree.to_string() );
}

int main( void )
{
	try
	{
		std::cout << "AB&!  :  " << negation_normal_form( "AB&!" ) << std::endl;
		std::cout << "AB|!  :  " << negation_normal_form( "AB|!" ) << std::endl;
		std::cout << "AB^  :  " << negation_normal_form( "AB^" ) << std::endl;
		std::cout << "AB^!  :  " << negation_normal_form( "AB^!" ) << std::endl;
		// std::cout << negation_normal_form( "AB>" ) << std::endl;
		// std::cout << negation_normal_form( "AB=" ) << std::endl;
		// std::cout << negation_normal_form( "AB|C&!" ) << std::endl;
	}
	catch(const std::invalid_argument& ia)
	{
		std::cerr << "Invalide Argument: \"" << "AB&!" << "\" " << ia.what() << std::endl;
		return 1;
	}
	return 0;
}


/* J'ai une string en entrer -> 

	--> Est-ce bien un RPN ?
	--> Creation de son AST.
	--> Transformation NNF.
	--> Return : creation de la formula.
*/