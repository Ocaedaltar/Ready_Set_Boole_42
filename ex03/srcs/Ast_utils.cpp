/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ast_utils.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 23:53:57 by mlormois          #+#    #+#             */
/*   Updated: 2022/12/08 04:48:04 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ast_utils.hpp"


namespace ft
{
	typedef Ast_node*	nodePTR;
	typedef Ast_node*	pointer;
	typedef Ast_node	reference;

/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */

	Ast_node::Ast_node( void ) :
		value(0), type(0), neg(false), parent(NULL), right(NULL), left(NULL)
	{
		// std::cout << "AST NODE default constructor" << std::endl;
	}

	Ast_node::Ast_node( Value value, Type type, nodePTR NIL) :
		value(value), type(type), neg(false), parent(NIL), right(NIL), left(NIL)
	{
		// std::cout << "AST NODE value constructor" << std::endl;
	}

	Ast_node::Ast_node( Ast_node const & cpy )
	{
		*this = cpy;
	}

	Ast_node::~Ast_node( void )
	{}

	// ATTENTION DEEPCOPIE PAS FAITE
	Ast_node & Ast_node::operator=( Ast_node const & cpy )
	{
		value = cpy.value;
		type = cpy.type;
		neg = cpy.neg;
		parent = cpy.parent;
		right = cpy.right;
		left = cpy.left;
		return *this;
	}

	void Ast_node::setNeg( void )
	{
		neg = ( !neg ? true : false );
	}

/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */

	Ast_iterator::Ast_iterator( void ) :
		_node(NULL), _root(NULL), NIL(NULL)
	{}

	Ast_iterator::Ast_iterator( nodePTR node, nodePTR root, nodePTR NIL ) :
		_node(node), _root(root), NIL(NIL)
	{}

	Ast_iterator::Ast_iterator( Ast_iterator const & cpy )
	{
		*this = cpy;
	}

	Ast_iterator::~Ast_iterator( void )
	{}

	Ast_iterator & Ast_iterator::operator=( Ast_iterator const & other )
	{
		_node = other._node;
		_root = other._root;
		NIL = other.NIL;
		return *this;
	}

	bool	Ast_iterator::operator==(const Ast_iterator& rhs) const
	{
		return (_node == rhs._node);
	}

	bool	Ast_iterator::operator!=(const Ast_iterator& rhs) const
	{
		return (_node != rhs._node);
	}

	reference	Ast_iterator::operator*(void) {return *_node; }
	pointer		Ast_iterator::operator->(void) {return _node; }

	Ast_iterator&	Ast_iterator::operator++()
	{
		if (_node != NIL)
			_node = _it_right();
		return *this;
	}

	Ast_iterator	Ast_iterator::operator++(int)
	{
		Ast_iterator tmp(*this); ++(*this); return tmp;
	}

	Ast_iterator&	Ast_iterator::operator--()
	{
		if (_node != NIL)
			_node = _it_left();
		else
			_node = _root;
		return *this;
	}

	Ast_iterator	Ast_iterator::operator--(int)
	{
		Ast_iterator tmp(*this); --(*this); return tmp;
	}

	nodePTR	Ast_iterator::_it_right( void )
	{
		nodePTR next = _node;
		nodePTR parent = _node->parent;

		if ( parent != NIL && next == parent->left )
			return _begin( parent->right );
		return parent;
	}

	nodePTR	Ast_iterator::_it_left( void )
	{
		nodePTR prev = _node;
		nodePTR parent = _node->parent;

		if (prev->right)
			return prev->right;
		else if ( parent != NIL && prev == parent->right )
			return _end( parent->left );
		return NIL;
	}

	nodePTR	Ast_iterator::_begin(nodePTR node)
	{
		while (node->left != NIL)
			node = node->left;
		return node;
	}

	nodePTR	Ast_iterator::_end(nodePTR node)
	{
		while (node->right != NIL)
			node = node->right;
		return node;
	}

/* ************************************************************************** */

}
