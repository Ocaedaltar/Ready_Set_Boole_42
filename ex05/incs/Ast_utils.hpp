/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ast_utils.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 05:58:22 by mlormois          #+#    #+#             */
/*   Updated: 2022/03/04 04:20:34 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_UTILS_HPP
# define AST_UTILS_HPP

# include <string>
# include <iostream>
# include <cmath>

namespace ft
{
	struct Ast_node
	{
	public:
		typedef Ast_node*	nodePTR;
		typedef char		Value;
		typedef int 		Type;

		Value		value;
		Type		type;
		bool		neg;
		nodePTR		parent;
		nodePTR		right;
		nodePTR		left;

		Ast_node( void );
		Ast_node( Value value, Type type, nodePTR NIL );
		Ast_node( Ast_node const & cpy );
		~Ast_node( void );

		Ast_node & operator=( Ast_node const & cpy );

		void setNeg( void );
	};
	
	class Ast_iterator
	{
	public:
		typedef Ast_node*	nodePTR;
		typedef Ast_node*	pointer;
		typedef Ast_node	reference;

		nodePTR	_node;
		nodePTR _root;
		nodePTR	 NIL;

		Ast_iterator( void );
		Ast_iterator( nodePTR node, nodePTR root, nodePTR NIL );
		Ast_iterator( Ast_iterator const & cpy );
		virtual ~Ast_iterator( void );

		Ast_iterator & operator=( Ast_iterator const & other );

		bool	operator==(const Ast_iterator& rhs) const;
		bool	operator!=(const Ast_iterator& rhs) const;

		reference	operator*(void);
		pointer		operator->(void);

		Ast_iterator&	operator++();
		Ast_iterator	operator++(int);
		Ast_iterator&	operator--();
		Ast_iterator	operator--(int);

	private:
		nodePTR	_it_right( void );
		nodePTR	_it_left( void );
		nodePTR	_begin(nodePTR node);
		nodePTR	_end(nodePTR node);
	};
}

#endif
