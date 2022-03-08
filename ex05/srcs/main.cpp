/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:35:10 by mlormois          #+#    #+#             */
/*   Updated: 2022/03/08 01:17:02 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "negation.hpp"

std::string negation_normal_form( std::string const & formula )
{
	// std::cout << std::endl << std::endl;
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
		// SIMPLE
		std::cout << "AB&!  :  " << negation_normal_form( "AB&!" ) << std::endl; // !(A & B) --> !A | !B
		std::cout << "AB|!  :  " << negation_normal_form( "AB|!" ) << std::endl;
		
		// MC
		std::cout << "AB>   :  " << negation_normal_form( "AB>" ) << std::endl;
		std::cout << "AB>!  :  " << negation_normal_form( "AB>!" ) << std::endl;

		// XOR
		std::cout << "AB^   :  " << negation_normal_form( "AB^" ) << std::endl;
		std::cout << "AB^!  :  " << negation_normal_form( "AB^!" ) << std::endl;

		// EGAL
		std::cout << "AB=   :  " << negation_normal_form( "AB=" ) << std::endl;
		std::cout << "AB=!  :  " << negation_normal_form( "AB=!" ) << std::endl;

		// EGAL
		std::cout << "AB|C&!:  " << negation_normal_form( "AB|C&!" ) << std::endl;
		// std::cout << "AB|C&!:  " << negation_normal_form( "AB|C&!" ) << std::endl;
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