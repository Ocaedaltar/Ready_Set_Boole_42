/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 20:29:26 by mlormois          #+#    #+#             */
/*   Updated: 2022/12/10 09:19:16 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Conjonctive.hpp"

std::string conjunctive_normal_form( std::string const & formula )
{
	ft::Ast tree( formula );
	tree.conjonctive_form();
	// tree.print();
	return tree.to_string();
}

static void ft_visualizer( std::string const & str ) {
	is_rpn( str );
	std::string nnf = conjunctive_normal_form( str );
	std::cout << str << "  =>  " << nnf << std::endl;
}

int main(int ac, char **av)
{
	for (int i = 1; i < ac; i++) {
		try {
			ft_visualizer(av[i]);
		} catch (std::invalid_argument const &e) {
			std::cerr << "Error: " << av[i] << ' ' << e.what() << std::endl;
			return 1;
		}
		std::cout << std::endl;
	}
	return 0;
}