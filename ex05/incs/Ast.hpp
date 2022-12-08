/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ast.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 05:28:40 by mlormois          #+#    #+#             */
/*   Updated: 2022/12/08 05:49:02 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_HPP
# define AST_HPP

# include <map>
# include <iterator>
# include <iostream>
# include <sstream>
# include <stack>
# include "Ast_utils.hpp"

# define M_BOOL "01&|^>=!"
# define M_VARS "ABCDEFGHIJKLMNOPQRSTUVWXYZ&|^>=!"

// Parsing:
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

		//////////////////////////
		//	 Member Types		//
		//////////////////////////

	public:
		typedef Ast_node*					nodePTR;
		typedef typename ft::Ast_iterator	iterator;
		typedef std::allocator<Ast_node>    allocator_type;


		//////////////////////////
		//	 Member variables	//
		//////////////////////////

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
		//	    Capacity:		//
		//////////////////////////

		nodePTR getNode( void ) const;

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
		void 	negation_form( void );

	private:
		void 	_fnn( nodePTR node );
		void 	_equivalence( nodePTR node );
		void 	_deMorganLaw( nodePTR node );

		void 	rewrite_egal( nodePTR node );
		void 	rewrite_xor( nodePTR node );
		void 	rewrite_mc( nodePTR node );

		nodePTR _copieNodes( nodePTR node );

		//////////////////////////
		//	    Operations:		//
		//////////////////////////
	
	public:
		std::string	to_string( void );
		bool		result( void );

		//////////////////////////
		//		  Utils:		//
		//////////////////////////
	
	private:
		bool _isVariable( char val );
		int  _takeType( char val );

	};
}

#endif