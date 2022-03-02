/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 04:33:40 by mlormois          #+#    #+#             */
/*   Updated: 2022/03/02 15:56:15 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ast_utils.hpp"
#include "Ast.hpp"

# define PRINT_BOOL( var ) std::cout << std::boolalpha << var << std::endl;

bool eval_formula( std::string const & str )
{
	std::cout << str << "  :  ";
	ft::Ast tree( str );
	return tree.result();
}

// Pourquoi un AST complet. 
//  Seulement pour le fun, je pourais faire seulement un stack et faire le developpement directement
//  Mais c'est simpa de faire son petit Ast tranquillou! 

int main( void )
{
	// Parsing a Ajouter, Neccecite un throw de la fonction
	// Donc main avec les try catch pour etre propre.

	PRINT_BOOL( eval_formula("10&") );
	PRINT_BOOL( eval_formula("10|") );
	PRINT_BOOL( eval_formula("11>") );
	PRINT_BOOL( eval_formula("10=") );
	PRINT_BOOL( eval_formula("1011||=") );

	// More Test Than Subject:
	PRINT_BOOL( eval_formula( "01&11&|") );
}
