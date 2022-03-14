/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 20:29:26 by mlormois          #+#    #+#             */
/*   Updated: 2022/03/09 00:15:42 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Conjonctive.hpp"

std::string conjunctive_normal_form( std::string const & formula )
{
	is_rpn( formula );
	ft::Ast tree( formula );
	tree.conjonctive_form();
	return tree.to_string();
}

int main( int ac, char **av )
{
	if ( ac != 2)
		return 1;

	try
	{
		conjunctive_normal_form( av[1] );
	}
	catch(const std::invalid_argument& ia)
	{
		std::cerr << "Invalide Argument: \"" << av[1] << "\" " << ia.what() << std::endl;
		return 1;
	}
	return (0);
}