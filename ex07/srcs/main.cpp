/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 20:29:26 by mlormois          #+#    #+#             */
/*   Updated: 2022/03/16 14:59:08 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Satisfaction.hpp"

bool sat( std::string const & formula )
{
	is_rpn( formula );
	ft::Ast tree( formula );
	tree.conjonctive_form();
	return tree.sat();
}

int main( int ac, char **av )
{
	if ( ac != 2)
		return 1;
	try
	{
		std::cout << "AB|" << ": " << std::boolalpha << sat("AB|") << std::endl;
		std::cout << "AB&" << ": " << std::boolalpha << sat("AB&") << std::endl;
		std::cout << "AA!&" << ": " << std::boolalpha << sat("AA!&") << std::endl;
		std::cout << "AA^" << ": " << std::boolalpha << sat("AA^") << std::endl;
		// std::cout << "complex:" << std::endl << "AB&CD&&AB|CD||&" << ": " << sat( "AB&CD&&AB|CD||&" ) << std::endl;
		std::cout << "your:" << std::endl << av[1] << ": " << std::boolalpha << sat( av[1] ) << std::endl;
	}
	catch(const std::invalid_argument& ia)
	{
		std::cerr << "Invalide Argument: \"" << av[1] << "\" " << ia.what() << std::endl;
		return 1;
	}
	return (0);
}