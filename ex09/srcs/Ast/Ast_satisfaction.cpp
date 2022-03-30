/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ast_satisfaction.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 03:04:34 by mlormois          #+#    #+#             */
/*   Updated: 2022/03/16 14:20:05 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ast.hpp"

namespace ft
{
	bool Ast::eval_formula( std::string const & formula )
	{
		bool a;
		bool b;
		std::stack<bool> res;

		for ( int i = 0; formula[i]; i++)
		{
			if ( formula[i] == '0' || formula[i] == '1' )
				res.push( formula[i] == '1' ? true : false );
			else if ( formula[i] == '!')
			{
				a = res.top(); res.pop();
				res.push( a == true ? false : true );
			}
			else
			{
				b = res.top(); res.pop();
				a = res.top(); res.pop();
				if ( formula[i] == '&' )
					res.push( (a == true && b == true) ? true : false);
				else if ( formula[i] == '|' )
					res.push( (a == true || b == true ) ? true : false);
				else if ( formula[i] == '^' )
					res.push( ( a != b ) ? true : false);
				else if ( formula[i] == '>' )
					res.push( ( a == true && b == false ) ? false : true);
				else if ( formula[i] == '=' )
					res.push( (a == b ) ? true : false);
			}
		}
		return res.top();
	}

	std::map<char, bool> Ast::ft_createMap( std::string const & str )
	{
		std::map<char, bool> ret;
		for ( int i = 0; str[i]; i++)
			if ( str[i] >= 'A' && str[i] <= 'Z' )
				ret.insert( std::make_pair( str[i] , false ));
		return ret;
	}

	bool Ast::makeTest( std::string const & formula, std::map<char, bool> map, int values )
	{
		int bitwise = 0;
		std::string ret;

		for (std::map<char, bool>::reverse_iterator it = map.rbegin(); it != map.rend(); it++ )
			it->second = values & (1 << bitwise++);
		for ( int i = 0; formula[i]; i++)
			ret.push_back((( formula[i] >= 'A' && formula[i] <= 'Z') ? (map.find(formula[i])->second == true ? '1' : '0' ) : formula[i] ));
		return eval_formula( ret );
	}

	bool	Ast::sat( void )
	{
		int ret = 0;
		std::string formula = this->to_string();
		std::map<char, bool> map = ft_createMap( formula );
		for ( size_t i = 0; i < std::pow( 2, map.size()); i++ )
			ret += makeTest( formula, map, i);
		return ( ret ? true : false );
	}
}