/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ast.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 05:28:40 by mlormois          #+#    #+#             */
/*   Updated: 2022/03/02 10:43:40 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_HPP
# define AST_HPP

# include <map>
# include <iterator>
# include <iostream>
# include "Ast_utils.hpp"
# include <stack>

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

		// Return le resultat de la formule si possible.
		bool result( void );
		// Affiche le resultat simple ou table de verite en fonction des variables.
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