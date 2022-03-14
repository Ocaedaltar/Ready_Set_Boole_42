/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ast_negative.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 20:34:35 by mlormois          #+#    #+#             */
/*   Updated: 2022/03/08 20:40:23 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ast.hpp"

namespace ft
{
	void Ast::negation_form( void )
	{
		_fnn( _root );
	}

	void Ast::_fnn( nodePTR node )
	{
		if ( node->type != BOOL)
		{
			if ( node->type > 2)
				_equivalence( node );
			if (node->neg)
				_deMorganLaw( node );
			if ( node->left != NIL )
				_fnn( node->left );
			if ( node->right != NIL )
				_fnn( node->right );
		}
	}

	void Ast::_deMorganLaw( nodePTR node )
	{
		node->value = ( node->type == OR ? '&' : '|' );
		node->type = ( node->type == OR ? AND : OR );
		node->left->setNeg();
		node->right->setNeg();
		node->setNeg();
	}

	void Ast::_equivalence( nodePTR node )
	{
		switch ( node->type )
		{
		case EGAL:
			rewrite_egal( node );
			break;
		case XOR:
			rewrite_xor( node );
			break;
		case MC:
			rewrite_mc( node );
			break;
		default:
			break;
		}
	}

	void Ast::rewrite_egal( nodePTR node )
	{
		nodePTR tmp_left;
		nodePTR tmp_right;

		// CHANGE ORIGIN
		node->value = '|';
		node->type = OR;
		// CREATE LEFT
		tmp_left = _node_create( '&', AND );
		tmp_left->left = _copieNodes(node->left);
		tmp_left->left->parent = tmp_left;
		tmp_left->right = _copieNodes(node->right);
		tmp_left->right->parent = tmp_left;
		// CREATE RIGHT
		tmp_right = _node_create( '&', AND);
		tmp_right->left = _copieNodes(node->left);
		tmp_right->left->parent = tmp_right;
		tmp_right->left->setNeg();
		tmp_right->right = _copieNodes(node->right);
		tmp_right->right->parent = tmp_right;
		tmp_right->right->setNeg();
		// DELETE OLD
		_clear(node->left);
		_clear(node->right);
		// LINK
		node->left = tmp_left;
		tmp_left->parent = node;
		node->right = tmp_right;
		tmp_right->parent = node;
	}

	void Ast::rewrite_xor( nodePTR node )
	{
		nodePTR tmp_left = _node_create( '&', AND );
		nodePTR tmp_right = _node_create( '|', OR);
		// CHANGE ORIGIN
		node->value = '&';
		node->type = AND;
		// CREATE LEFT
		tmp_left->setNeg();
		tmp_left->left = _copieNodes(node->left);
		tmp_left->left->parent = tmp_left;
		tmp_left->right = _copieNodes(node->right);
		tmp_left->right->parent = tmp_left;
		// CREATE RIGHT
		tmp_right->left = _copieNodes(node->left);
		tmp_right->left->parent = tmp_right;
		tmp_right->right = _copieNodes(node->right);
		tmp_right->right->parent = tmp_right;
		// DELETE OLD
		_clear(node->left);
		_clear(node->right);
		// LINK
		node->left = tmp_left;
		tmp_left->parent = node;
		node->right = tmp_right;
		tmp_right->parent = node;
	}

	void Ast::rewrite_mc( nodePTR node )
	{
		node->value = '|';
		node->type = OR;
		node->left->setNeg();
	}
}
