/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ast_conjonctive.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 21:15:45 by mlormois          #+#    #+#             */
/*   Updated: 2023/02/01 15:49:19 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ast.hpp"

namespace ft
{
	void	Ast::conjonctive_form( void )
	{
		this->negation_form();
		// print();
		_fcn( _root );
		// std::cout << std::endl;
		// print();
	}

	void 	Ast::_fcn( nodePTR node )
	{
		nodePTR tmp_right = node->right;
		nodePTR tmp_left  = node->left;
		_conjonctive( node );
		if (tmp_right != NIL)
			_fcn( tmp_right );
		if (tmp_left != NIL)
			_fcn( tmp_left);
	}

	void	Ast::_conjonctive( nodePTR node )
	{
		if ( node->type == BOOL )
			return ;
		if (node->left->type != BOOL && node->type == node->left->type)
		{
			nodePTR opp = node->left;
			if (opp->right->type == BOOL || opp->left->type == BOOL )
			{
				nodePTR oParent = node->parent;
				const int sense_zero = (oParent != NIL ? (oParent->left == node ? LEFT : RIGHT ) : 0);
				const int sense_two = (opp->right->type == BOOL ? RIGHT : LEFT);
				nodePTR oChild = (sense_two == RIGHT ? opp->right : opp->left);
				// On replace OPP
				opp->parent = oParent;
				if (oParent == NIL)
					_root = opp;
				else
					( sense_zero == RIGHT ? oParent->right : oParent->left ) = opp;
				// // On place NODE
				( sense_two == RIGHT ? opp->right : opp->left ) = node;
				node->parent = opp;
				// // On place CHILD S2
				oChild->parent = node;
				node->left = oChild;
			}
		}
	}

	// Equilibre mon arbre -> pas vraiment le but de l'exo
	// void	Ast::_repartition( nodePTR node )
	// {
	// 	if ( node->type == BOOL )
	// 		return ;
	// 	// Si un des deux enfant de node est une feuille
	// 	if 	( (node->right->type == BOOL && node->left->type  != BOOL)
	// 		|| (node->left->type == BOOL && node->right->type != BOOL) )
	// 	{
	// 		// sense_one represente le sens vers la node feuille ( BOOL )
	// 		const int sense_one = (node->left->type == BOOL ? LEFT : RIGHT);
	// 		nodePTR opp = ( node->right->type == BOOL ? node->left : node->right );
	// 		// Si un des deux enfant de opp est une feuille
	// 		if 	( (opp->right->type == BOOL && opp->left->type  != BOOL)
	// 			|| (opp->left->type == BOOL && opp->right->type != BOOL) )
	// 		{
	// 			// <-----------  si node = _root -> SEGFAULT
	// 			nodePTR oParent = node->parent;
	// 			const int sense_zero = (oParent != NIL ? (oParent->left == node ? LEFT : RIGHT ) : 0);
	// 			const int sense_two = (opp->left->type == BOOL ? LEFT : RIGHT);
	// 			nodePTR oChild = (sense_two == RIGHT ? opp->right : opp->left);
	// 			// ici: j'ai toute les info pour faire mes swap de ptr.
	// 			// On place OPP:
	// 			opp->parent = oParent;
	// 			if (oParent == NIL)
	// 				_root = opp;
	// 			else
	// 				( sense_zero == RIGHT ? oParent->right : oParent->left ) = opp;
	// 			// On place NODE
	// 			node->parent = opp;
	// 			( sense_two == RIGHT ? opp->right : opp->left ) = node;
	// 			// On place CHILD S2
	// 			oChild->parent = node;
	// 			( sense_one == RIGHT ? node->left : node->right ) = oChild;
	// 		}
	// 	}
	// }
}
