/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 04:33:40 by mlormois          #+#    #+#             */
/*   Updated: 2022/03/02 15:23:56 by mlormois         ###   ########.fr       */
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
