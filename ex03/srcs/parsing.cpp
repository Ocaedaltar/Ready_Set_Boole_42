/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 04:43:07 by mlormois          #+#    #+#             */
/*   Updated: 2022/12/08 05:08:56 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ast.hpp"

static bool check_char( std::string const & formula, int mode = 0 ) {
	return formula.find_first_not_of( mode ? M_VARS : M_BOOL ) != std::string::npos;
}

static bool check_syntax( std::string const & formula) 
{
	std::stack< bool > save;
	std::string opp = "&|^>=";
	bool flag = false;

	for ( char letter : formula ) {
		if ( opp.find(letter) != std::string::npos ) {
			if (save.size() == 0) {
				return true;
			}
			flag = true;
			save.pop();
		} else if ( letter != '!' ) {
			save.push( true );
		}
	}
	return ((save.size() == 1 && flag) ? false : true );
}

void is_rpn( std::string const & formula )
{
	if ( check_char( formula ))
		std::__throw_invalid_argument( "have a bad caractere." );
	if ( check_syntax( formula ) )
		std::__throw_invalid_argument( "isnt a valide RPN." );
}