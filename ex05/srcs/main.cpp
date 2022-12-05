/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:35:10 by mlormois          #+#    #+#             */
/*   Updated: 2022/12/05 17:28:30 by mlormois         ###   ########.fr       */
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
	// tree.print();
	// Return de la string grace a l'arbre de substiue en NNF
	return ( tree.to_string() );
}

int main( void )
{
	try
	{
		// SIMPLE
		// std::cout << "AB&C&D&   :  \n" << negation_normal_form( "AB&C&D&" ) << std::endl;
		std::cout << "AB&!  :  " << negation_normal_form( "AB&!" ) << SPACE; // !(A & B) --> !A | !B
		std::cout << "AB|!  :  "  << negation_normal_form( "AB|!" ) << SPACE;
		
		// MC
		std::cout << "AB>   :  " << negation_normal_form( "AB>" ) << SPACE;
		std::cout << "AB>!  :  " << negation_normal_form( "AB>!" ) << SPACE;

		// XOR
		std::cout << "AB^   :  " << negation_normal_form( "AB^" ) << SPACE;
		std::cout << "AB^!  :  " << negation_normal_form( "AB^!" ) << SPACE;

		// EGAL
		std::cout << "AB=   :  " << negation_normal_form( "AB=" ) << SPACE;
		std::cout << "AB=!  :  "<< negation_normal_form( "AB=!" ) << SPACE;

		// EGAL
		std::cout << "AB|C&!:  " << negation_normal_form( "AB|C&!" ) << SPACE;
		std::cout << "AB|C&!:  " << negation_normal_form( "AB|C&!" ) << SPACE;
	}
	catch(const std::invalid_argument& ia)
	{
		std::cerr << "Invalide Argument: expression " << ia.what() << SPACE;
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