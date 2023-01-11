/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 22:22:20 by mlormois          #+#    #+#             */
/*   Updated: 2023/01/11 15:33:24 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ast.hpp"

static bool check_char( std::string const & formula, int mode )
{
	return formula.find_first_not_of( mode ? M_VARS : M_BOOL ) != std::string::npos;
}

static bool check_syntax( std::string const & formula) 
{
	std::stack< bool > save;
	std::string opp = "&|^>=";

	for ( size_t i = 0; formula[i]; i++ )
	{
		if ( opp.find(formula[i]) != std::string::npos )
		{
			if (save.size() == 0)
				break ;
			save.pop();
		}
		else if ( formula[i] != '!' )
			save.push( true );
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