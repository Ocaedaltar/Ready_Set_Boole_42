/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ast.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 20:30:00 by mlormois          #+#    #+#             */
/*   Updated: 2022/12/10 09:20:09 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_HPP
# define AST_HPP

# include <map>
# include <stack>
# include <iterator>

# include <sstream>
# include <iostream>

# include "Ast_utils.hpp"

# define M_BOOL "01&|^>=!"
# define M_VARS "ABCDEFGHIJKLMNOPQRSTUVWXYZ&|^>=!"

# define RIGHT 1
# define LEFT 2

typedef ft::Ast_node*					nodePTR;
typedef typename ft::Ast_iterator		iterator;
typedef std::allocator<ft::Ast_node>    allocator_type;
typedef std::stack< nodePTR >			Stack;

namespace ft
{

	class Ast
	{
	private:
		std::map< char, bool >		_vars;
		nodePTR						_root;
		nodePTR						NIL;
		allocator_type				_alloc;

		//////////////////////////
		//	   Constructors:	//
		//////////////////////////

	public:
		Ast( std::string const & formula );

	private:
		nodePTR 	_createNIL( void );
		nodePTR		_node_create( char value, int type );

		Ast( void );
		Ast( Ast const & cpy );
		Ast & operator=( Ast const & other );

		//////////////////////////
		//	   Destructors:		//
		//////////////////////////
	public:
		virtual ~Ast( void );

	private:
		void _clear( nodePTR node );
		void _destroy_node(nodePTR node);

		//////////////////////////
		//	   Iterators:		//
		//////////////////////////

	public:
		iterator begin( void );
		iterator end( void );

	private:
		nodePTR	_begin( nodePTR node);
		nodePTR	_end( nodePTR node);

		//////////////////////////
		//	    Observers:		//
		//////////////////////////

	public:
		void	print(const std::string &formula);

	private:
		void	_print(nodePTR node, std::stringstream &buffer, bool isTail, std::string prefix);

		//////////////////////////
		//	    Modifiers:		//
		//////////////////////////

	public:
		void	conjonctive_form( void );
		void 	negation_form( void );

	private:
		void 	_fnn( nodePTR node );
		void 	_equivalence( nodePTR node );
		void 	_deMorganLaw( nodePTR node );
		void 	rewrite_egal( nodePTR node );
		void 	rewrite_xor( nodePTR node );
		void 	rewrite_mc( nodePTR node );
		nodePTR _copieNodes( nodePTR node );

		void 	_fcn( nodePTR node );
		void	_conjonctive( nodePTR node );
		// void	_repartition( nodePTR node );

		//////////////////////////
		//	    Operations:		//
		//////////////////////////
	
	public:
		std::string	to_string( void );
		bool		result( void );

	private:
		bool _isVariable( char val );
		int  _takeType( char val );

	};

}


#endif