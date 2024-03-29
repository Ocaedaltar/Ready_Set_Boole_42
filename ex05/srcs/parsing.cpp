/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 22:22:20 by mlormois          #+#    #+#             */
/*   Updated: 2022/12/08 04:42:37 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ast.hpp"

static bool check_char( std::string const & formula, int mode ) {
	return formula.find_first_not_of( mode ? M_VARS : M_BOOL ) != std::string::npos;
}

static bool check_syntax( std::string const & formula) 
{
	std::stack< bool > save;
	std::string opp = "&|^>=";

	for ( char letter : formula ) {
		if ( opp.find(letter) != std::string::npos ) {
			if (save.size() == 0) {
				return true;
			}
			save.pop();
		} else if ( letter != '!' ) {
			save.push( true );
		}
	}
	return ((save.size() == 1) ? false : true );
}

void is_rpn( std::string const & formula )
{
	if ( check_char( formula, 1 ))
		std::__throw_invalid_argument( "have a bad caractere." );
	if ( check_syntax( formula ) )
		std::__throw_invalid_argument( "isnt a valide RPN." );
}