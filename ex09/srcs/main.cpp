/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 20:43:14 by mlormois          #+#    #+#             */
/*   Updated: 2022/03/30 14:28:03 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SetEvaluation.hpp"

int add_unique_value( Set const & list, int const & max )
{
	int value = rand() % max;
	return ( std::find( list.begin(), list.end(), value) != list.end() ? add_unique_value( list, max ) : value );
}

void set_print( Set data )
{
	std::cout << "[";
	for ( size_t i = 0; i < data.size(); i++ )
	{
		std::cout << data[i];
		if ( i < data.size() - 1 )
			std::cout << ", ";
	}
	std::cout << "]" << std::endl;
}

void sets_print( Sets data )
{
	std::cout << "Sets:" << std::endl;
	for ( size_t i = 0; i < data.size(); i++ )
	{
		std::cout << i << " : ";
		set_print( data[i] );
	}
}

Sets make_sets( int number, int range, int max )
{
	Sets tab_set;
	for ( int i = 0; i < number; i++)
	{
		Set elem;
		for ( int i = 0; i < range; i++)
			elem.push_back( add_unique_value( elem, max ) );
		std::sort(elem.begin(), elem.end());
		tab_set.push_back(elem);
	}
	return tab_set;
}

int main( void )
{
	srand( time( NULL ) );
	Sets tab_set = make_sets( 2 , 2 , 2);
	sets_print( tab_set );
	set_print( eval_set( "AB!|", tab_set) );
	return 0;
}
