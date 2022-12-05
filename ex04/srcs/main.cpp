/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:27:56 by mlormois          #+#    #+#             */
/*   Updated: 2022/12/05 17:19:19 by mlormois         ###   ########.fr       */
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
	int i =0;
	for (std::map<char, bool>::iterator it = map.begin(); it != map.end(); it++ )
	{
		i++;
		std::cout << "| " << it->first << " ";
	}
	std::cout << "| = |"<< std::endl;
	for ( int j= 0; j < i+1; j++)
	 	std::cout << "|---";
	std::cout << "|" << std::endl;
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

bool little_check_letter( std::string const & str ) {
	if (str.size() < 3)
		return true;
	if (str[0] < 'A' || str[0] > 'Z')
		return true;
	int number = 0, opp = 0;
	for ( int i = 0; int(str.size()) > i; i++) {
		if (str[i] >= 'A' && str[i] <= 'Z')
			number++;
		else if ( str[i] == '&' || str[i] == '|' || str[i] == '=' || str[i] == '|' || str[i] == '^' || str[i] == '>')
			opp++;
		else if ( str[i] != '!' ) // PAS UN CHAR VALIDE
			return true;
	}
	if (number - opp != 1)
		return true;
	return false;
}


void print_truth_table( std::string const & str)
{
	if (little_check_letter(str)) {
		std::cout << "Error: expression " << str << " was invalid!" << std::endl;
		return;
	}

	std::map<char, bool> map = ft_createMap( str );
	print_header( map );
	for ( size_t i = 0; i < std::pow( 2, map.size()); i++ )
		makeTest( str, map, i);
}

int main( void )
{
	// print_truth_table( "A!!B|!" );
	print_truth_table( "AB&C|DA&A|&" );

	print_truth_table( "&|" );
	print_truth_table( "01&" );
	print_truth_table( "AB" );
	print_truth_table( "ABAB&&" );
	print_truth_table( "A&&&&&" );
	print_truth_table( "AB!!!!!" );
	print_truth_table( "" );
}