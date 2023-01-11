/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:35:10 by mlormois          #+#    #+#             */
/*   Updated: 2023/01/11 15:31:42 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "negation.hpp"

std::string negation_normal_form( std::string const & formula )
{
	ft::Ast tree( formula );
	// tree.print(formula);
	tree.negation_form();
	// tree.print(tree.to_string());
	return (tree.to_string());
}

static void ft_visualizer( std::string const & str ) {
	is_rpn( str );
	std::string nnf = negation_normal_form( str );
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