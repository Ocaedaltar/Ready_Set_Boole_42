/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:54:19 by mlormois          #+#    #+#             */
/*   Updated: 2022/12/10 10:50:12 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Powerset.hpp"

// fn powerset(set: &[i32]) -> Vec<Vec<i32>>;
// --> je suis pas sur pour &[i32] => je prend un vector.

std::vector<std::vector<int>> powerset( std::vector<int> set )
{
	std::vector<std::vector<int>> powSet;
	size_t size = set.size();

	for ( size_t i = 0; i < std::pow(2, size); i++)
	{
		std::vector<int> newSet;
		for (size_t j = 0; j < size; j++)
			if (i & (1 << j))
				newSet.push_back( set[j] );
		powSet.push_back( newSet );
	}
	return powSet;
}

void print_vector( std::vector<int> set )
{
	size_t size = set.size();
	std::cout << "{";
	for (size_t i = 0; i < set.size(); i++)
		std::cout << set[i] << ( i < size - 1 ? ", " : "");
	std::cout << "}";
}

void print_powerset( std::vector<int> set, std::vector<std::vector<int>> powset )
{
	size_t size = powset.size();
	std::cout << "set = ";
	print_vector( set );
	std::cout << std::endl << "P(set) = {";
	for (size_t i = 0; i < size; i++)
	{
		print_vector( powset[i] );
		std::cout << ( i < size - 1 ? ", " : "");
	}
	std::cout << "}" << std::endl;
}

int main( int ac, char **av )
{
	std::vector<int> alpha;

	try {
		for (int i = 1; i < ac; i++)
			alpha.push_back( std::stoi(av[i]) );
		print_powerset( alpha, powerset(alpha) );
	} catch (std::invalid_argument const &e) {
			std::cerr << "Error: " << e.what() << std::endl;
			return 1;
	}
	return 0;
}