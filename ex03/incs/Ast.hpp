/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ast.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 05:28:40 by mlormois          #+#    #+#             */
/*   Updated: 2022/12/08 05:03:10 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_HPP
# define AST_HPP

# include <map>
# include <iterator>
# include <iostream>
# include "Ast_utils.hpp"
# include <stack>

# define ERR_NARG(x) std::cerr << "Error: too " << (x < 2 ? "less" : "much" ) << " number of arguments" << std::endl
# define ERR_ARG std::cerr << "Error: bad arguments" << std::endl
# define ERR_RAN std::cerr << "Error: argument out of range" << std::endl

# define M_BOOL "01&|^>=!"
# define M_VARS "ABCDEFGHIJKLMNOPQRSTUVWXYZ&|^>=!"

void is_rpn( std::string const & formula );

namespace ft
{
	enum type
	{
		BOOL = 0,
		AND,
		OR,
		XOR,
		MC,
		EGAL
	};

	class Ast
	{
	public:
		typedef Ast_node*					nodePTR;
		typedef typename ft::Ast_iterator	iterator;
		typedef std::allocator<Ast_node>    allocator_type;

	private:
		std::map< char, bool >		_vars;
		nodePTR						_root;
		nodePTR						NIL;
		allocator_type				_alloc;

		Ast( void );
		Ast( Ast const & cpy );
		Ast & operator=( Ast const & other );
	public:
		Ast( std::string const & formula );
		virtual ~Ast( void );

		iterator begin( void );
		iterator end( void );

		bool result( void );
		void printTable( void );

	private:
		void _clear( nodePTR node );
		void _destroy_node(nodePTR node);

		bool _isVariable( char val );
		int  _takeType( char val );

		nodePTR 	_createNIL( void );
		nodePTR		_node_create( char value, int type );
		nodePTR		_begin( nodePTR node);

	};
}

#endif