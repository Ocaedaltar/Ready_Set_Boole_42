/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 04:33:40 by mlormois          #+#    #+#             */
/*   Updated: 2022/12/01 13:50:43 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ast_utils.hpp"
#include "Ast.hpp"

# define PRINT_BOOL( var ) std::cout << std::boolalpha << var << std::endl;


bool little_check( std::string const & str ) {
	if (str.size() < 3)
		return true;
	if (str[0] != '0' && str[0] != '1')
		return true;
	int number = 0, opp = 0;
	for ( int i = 0; int(str.size()) > i; i++) {
		if ( str[i] == '0' || str[i] == '1')
			number++;
		else if ( str[i] == '&' || str[i] == '|' || str[i] == '=' || str[i] == '|' || str[i] == '^' || str[i] == '>')
			opp++;
		else if ( str[i] != '!' ) // PAS UN CHAR VALIDE
			return true;
	}
	if (number - opp != 1)
		return true;
	return false;
}

bool eval_formula( std::string const & str )
{
	if ( little_check(str) == true )
		return false;

	std::cout << str << "  :  ";
	ft::Ast tree( str );
	return tree.result();
}

// Pourquoi un AST complet. 
//  Seulement pour le fun, je pourais faire seulement un stack et faire le developpement directement
//  Mais c'est sympa de faire son petit Ast tranquillou! 

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
	PRINT_BOOL( eval_formula( "0111^=|") );

	// Undefined Test:
	std::cout << "\nUndefined Test\n\n";

	PRINT_BOOL( eval_formula( "&|") );
	PRINT_BOOL( eval_formula( "01") );
	PRINT_BOOL( eval_formula( "26|") );
	PRINT_BOOL( eval_formula( "a2&") );
	PRINT_BOOL( eval_formula( "01&01&") );
	PRINT_BOOL( eval_formula( "1&&&&&") );
	PRINT_BOOL( eval_formula( "1!!!!!!") );

}
