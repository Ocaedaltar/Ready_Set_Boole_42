/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:27:56 by mlormois          #+#    #+#             */
/*   Updated: 2022/03/03 22:44:58 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "Ast.hpp"
// #include "Ast_utils.hpp"

#include <map>
#include <cmath>
#include <stack>
#include <string>
#include <iostream>
#include <iterator>

bool eval_formula( std::string const & formula )
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

std::map<char, bool> ft_createMap( std::string const & str )
{
	std::map<char, bool> ret;;
	for ( int i = 0; str[i]; i++)
		if ( str[i] >= 'A' && str[i] <= 'Z' )
			ret.insert( std::make_pair( str[i] , false ));
	return ret;
}

void print_header( std::map<char, bool> map )
{
	for (std::map<char, bool>::iterator it = map.begin(); it != map.end(); it++ )
		std::cout << "| " << it->first << " ";
	std::cout << "| = |"<< std::endl << "|---|---|---|---|" << std::endl;
}

void print_resultat( std::map<char, bool> map, std::string const & formula )
{
	for ( std::map<char, bool>::iterator it = map.begin(); it != map.end(); it++ )
		std::cout << "| " << it->second << " ";
	std::cout << "| " << eval_formula( formula ) << " |" << std::endl;
}

void makeTest( std::string const & formula, std::map<char, bool> map, int values )
{
	int bitwise = 0;
	std::string ret;

	for (std::map<char, bool>::reverse_iterator it = map.rbegin(); it != map.rend(); it++ )
		it->second = values & (1 << bitwise++);
	for ( int i = 0; formula[i]; i++)
		ret.push_back((( formula[i] >= 'A' && formula[i] <= 'Z') ? (map.find(formula[i])->second == true ? '1' : '0' ) : formula[i] ));
	print_resultat( map, &ret[0] );
}

void print_truth_table( std::string const & str)
{
	std::map<char, bool> map = ft_createMap( str );
	print_header( map );
	for ( size_t i = 0; i < std::pow( 2, map.size()); i++ )
		makeTest( str, map, i);
}

int main( void )
{
	// print_truth_table( "A!!B|!" );
	print_truth_table( "AB&C|DA&A|&" );
}