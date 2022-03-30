/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_set.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 00:06:34 by mlormois          #+#    #+#             */
/*   Updated: 2022/03/30 14:29:02 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SetEvaluation.hpp"

// fn eval_set(formula: &str, sets: &[[i32]]) -> Vec<i32>;

std::string conjunctive_normal_form( std::string const & formula )
{
	ft::Ast tree( formula );
	tree.conjonctive_form();
	return tree.to_string();
}

Set substract( Node a, Node b )
{
	Set dest;
	for ( Set::iterator it = a.value.begin(); it != a.value.end(); it++ )
	{
		int gate = 0;
		for ( Set::iterator jt = b.value.begin(); jt != b.value.end(); jt++ )
		{
			if ( *it == *jt )
			{
				gate = 1;
				break;
			}
		}
		if ( !gate )
		{
			dest.push_back(*it);
		}
	}
	return dest;
}

Set ft_uranus( Node a, Node b )
{
	Set dest = substract(a, b);
	Set add = substract(b, a);
	for ( Set::iterator it = add.begin(); it != add.end(); it++ )
		dest.push_back( *it );
	std::sort(dest.begin(), dest.end());
	return dest;
}

Set ft_union( Node a, Node b )
{
	Set dest = b.value;
	Set add = substract(a, b);
	for ( Set::iterator it = add.begin(); it != add.end(); it++ )
		dest.push_back( *it );
	std::sort(dest.begin(), dest.end());
	return dest;
}

Set ft_inter( Node a, Node b )
{
	Set dest;
	for ( Set::iterator it = a.value.begin(); it != a.value.end(); it++ )
	{
		int gate = 0;
		for ( Set::iterator jt = b.value.begin(); jt != b.value.end(); jt++ )
		{
			if ( *it == *jt )
			{
				gate = 1;
				break;
			}
		}
		if ( gate )
		{
			dest.push_back(*it);
		}
	}
	return dest;
}

Set makeAnd( Node a, Node b )
{
	if ( a.neg && b.neg )
		return Set();
	else if ( !a.neg && !b.neg )
		return ft_inter( a, b );
	return (a.neg ? substract( a, b ) : substract( b, a ));
}

Set makeOr( Node a, Node b )
{
	if ( a.neg && b.neg )
		return ft_uranus( a, b );
	else if ( !a.neg && !b.neg )
		return ft_union(a, b); 
	return (a.neg ? b.value : a.value );
}

Set eval_set( std::string formula, Sets sets)
{
	std::stack<Node> res;
	std::string fnc = conjunctive_normal_form( formula );
	std::cout << fnc << std::endl;
	for (int i = 0; fnc[i]; i++)
	{
		if ( fnc[i] >= 'A' && fnc[i] <= 'Z' )
			res.push( Node(sets[ fnc[i] - MAJ_TO_DIG ], false));
		else if ( fnc[i] == '!')
			res.top().setNeg();
		else
		{
			Node a = res.top(); res.pop();
			Node b = res.top(); res.pop();
			res.push( Node( (fnc[i] == '&' ? makeAnd( a , b ) : makeOr( a , b ) ), 0) );
		}
	}
	return ( res.top().value);
}