/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 20:43:14 by mlormois          #+#    #+#             */
/*   Updated: 2023/01/11 15:50:32 by mlormois         ###   ########.fr       */
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

int countVar( std::string formula ) {
	int count = 0;
	for (int i = 0; formula[i] != '\0'; i++) {
		if ( formula[i] >= 'A' && formula[i] <= 'Z') {
			if (i == 0)
				count++;
			for (int j = i - 1; j >= 0; j-- ) {
				if (formula[i] == formula[j])
					break ;
				if (j == 0)
					count++;
			}
		}
	}
	std::cout << "N VAR: " << count << std::endl;
	return count;
}

Sets make_sets( char *formula, int range, int max )
{
	Sets tab_set;
	int nvar = countVar(formula);
	if ( range > max )
		return tab_set;
	for ( int i = 0; i < nvar; i++)
	{
		Set elem;
		for ( int i = 0; i < range; i++)
			elem.push_back( add_unique_value( elem, max ) );
		std::sort(elem.begin(), elem.end());
		tab_set.push_back(elem);
	}
	return tab_set;
}

int main( int ac, char **av )
{
	srand( time( NULL ) );
	
	if (ac != 2)
		return 1;

	Sets tab_set = make_sets( av[1], 4 , 10);

	if ( tab_set.size() == 0 )
		return (std::cout << "Error: make_sets invalid\n", 1);
	sets_print( tab_set );
	std::cout << std::endl;

	try {
		set_print( eval_set( av[1], tab_set) );
	} catch(const std::invalid_argument& ia)
	{
		std::cerr << "Invalide Argument: expression " << ia.what() << std::endl;
		return 1;
	}

	return 0;
}
