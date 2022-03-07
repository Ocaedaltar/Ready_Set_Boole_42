/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ast.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 23:53:48 by mlormois          #+#    #+#             */
/*   Updated: 2022/03/07 16:01:20 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ast.hpp"

namespace ft
{
	typedef Ast_node*					nodePTR;
	typedef typename ft::Ast_iterator	iterator;
	typedef std::allocator<Ast_node>    allocator_type;
	typedef std::stack< nodePTR >		Stack;

	Ast::Ast( void )
	{}

	nodePTR Ast::_createNIL( void )
	{
		nodePTR node = _alloc.allocate(1);
		_alloc.construct(node, Ast_node());
		node->left = node;
		node->parent = node;
		node->right = node;
		return node;
	}

	nodePTR	Ast::_node_create( char value, int type )
	{
		nodePTR elem = _alloc.allocate(1);
		_alloc.construct(elem, value, type, NIL);
		return elem;
	}

	bool Ast::_isVariable( char val )
	{
		if ( val == '0' || val == '1' )
			return 0;
		else if ( val >= 'A' && val <= 'Z' )
		{
			// std::map< char, bool>::iterator it = _vars.find( val );
			// if (it == _vars.end())
			_vars.insert( std::pair<char, bool>( val, true));
			return 0;
		}
		return 1;	
	}

	int  Ast::_takeType( char val )
	{
		return ( AND * ( val == '&') + OR * ( val == '|') + XOR * ( val == '^') 
				+ MC * ( val == '>' ) + EGAL * ( val == '=' ));
	}

	Ast::Ast( std::string const & formula )
	{
		char value;
		Stack save;
		NIL = _createNIL();
		int ret;

		nodePTR elem;
		nodePTR tmp_a;
		nodePTR tmp_b;
		for ( size_t i = 0; i < formula.size(); i++)
		{
			value = formula[i];
			// std::cout << formula[i] << std::endl;

			if ( !_isVariable( value ) )
			{
				save.push( _node_create( value, 0) );
			}
			else if ( (ret = _takeType( value )) )
			{
				tmp_a = save.top(); 
				save.pop();
				tmp_b = save.top(); 
				save.pop();
				elem = _node_create(value, ret);
				elem->right = tmp_a;
				elem->left = tmp_b;
				tmp_a->parent = elem;
				tmp_b->parent = elem;
				save.push( elem );
			}
			else if ( value == '!' )
				save.top()->setNeg();
			else
				break;
		}
		_root = save.top();
	}
	
	Ast::~Ast( void )
	{
		_clear( _root );
		_destroy_node(NIL);
	}

	iterator Ast::begin( void )
	{
		return iterator(_begin(_root), _root, NIL);
	}
	
	iterator Ast::end( void )
	{
		return iterator( NIL, _root, NIL);
	}

	void Ast::_clear( nodePTR node )
	{
		if (node != NIL)
		{
			if (node->left != NIL)
				_clear(node->left);
			if (node->right != NIL)
				_clear(node->right);
			_destroy_node(node);
			node = NIL;
		}
	}

	nodePTR Ast::_begin( nodePTR node)
	{
		while (node->left != NIL)
			node = node->left;
		return node;
	}

	void Ast::_destroy_node(nodePTR node)
	{
		_alloc.destroy(node);
		_alloc.deallocate(node, 1);
	}


	// nodePTR Ast::getNode( void ) const
	// {
	// 	return _node;
	// }

	bool Ast::result( void )
	{
		// std::cout << " PRINT RES: " << std::endl;
		// for ( iterator it = begin(); it != end(); it++)
		// {
		// 	std::cout << it->value << " ";
		// }
		// std::cout << std::endl;

		bool a;
		bool b;

		std::stack<bool> res;

		for ( iterator it = begin(); it != end(); it++ )
		{
			if (it->type == BOOL)
				res.push( it->value == '0' ? false : true );
			else
			{
				b = res.top(); res.pop();
				a = res.top(); res.pop();
				switch (it->type)
				{
				case AND:
					res.push( (a == true && b == true) ? true : false);
					break;
				case OR:
					res.push( (a == true || b == true ) ? true : false);
					break;
				case XOR:
					res.push( ( a != b ) ? true : false);
					break;
				case MC:
					res.push( ( a == true && b == false ) ? false : true);
					break;
				case EGAL:
					res.push( (a == b ) ? true : false);
					break;
				default:
					break;
				}
			}
		}
		return res.top();
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
			if ( node->left )
				_fnn( node->left );
			if ( node->right )
				_fnn( node->right );
		}
	}

	void Ast::rewrite_egal( nodePTR node )
	{
		nodePTR tmp_left;
		nodePTR tmp_right;

		// CHANGE ORIGIN
		node->value = '&';
		node->type = AND;

		// CREATE LEFT
		tmp_left = _node_create( '>', MC );
		tmp_left->left = _copieNodes(node->left);
		tmp_left->right = _copieNodes(node->right);

		// CREATE RIGHT
		tmp_right = _node_create( '>', MC);
		tmp_right->left = _copieNodes(node->left);
		tmp_right->right = _copieNodes(node->right);

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
		nodePTR tmp_left;
		nodePTR tmp_right;

		// CHANGE ORIGIN
		node->value = '&';
		node->type = AND;

		// CREATE LEFT
		tmp_left = _node_create( '&', AND );
		tmp_left->setNeg();
		tmp_left->left = _copieNodes(node->left);
		tmp_left->right = _copieNodes(node->right);

		// CREATE RIGHT
		tmp_right = _node_create( '|', OR);
		tmp_right->left = _copieNodes(node->left);
		tmp_right->right = _copieNodes(node->right);

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
	
	nodePTR Ast::_copieNodes( nodePTR const & node )
	{
		nodePTR elem = _node_create(node->value, node->type);
		if ( node->left )
		{
			elem->left = _copieNodes( node->left );
			elem->left->parent = elem;
		}
		if ( node->right )
		{
			elem->right = _copieNodes( node->right );
			elem->right->parent = elem;
		}
		return elem;
	}

	std::string Ast::to_string( void )
	{
		std::string dst;
		for ( iterator it = begin(); it != end(); it++)
		{
			dst.push_back( it->value );
			if ( it->neg )
				dst.push_back('!');
		}
		return dst;
	}

}