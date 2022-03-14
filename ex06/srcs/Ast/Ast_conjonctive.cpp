/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ast_conjonctive.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 21:15:45 by mlormois          #+#    #+#             */
/*   Updated: 2022/03/09 00:37:17 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ast.hpp"

namespace ft
{
	void	Ast::conjonctive_form( void )
	{
		this->negation_form();
		print();
		_fcn( _root );
	}

	void 	Ast::_fcn( nodePTR node )
	{
		( void )node;
	}

}
