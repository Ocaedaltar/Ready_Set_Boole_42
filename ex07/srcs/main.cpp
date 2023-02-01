/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 20:29:26 by mlormois          #+#    #+#             */
/*   Updated: 2023/01/27 13:55:47 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Satisfaction.hpp"

bool sat( std::string const & formula )
{
	ft::Ast tree( formula );
	tree.conjonctive_form();
	return tree.sat();
}

static void ft_visualizer( std::string const & str ) {
	is_rpn( str );
	bool nnf = sat( str );
	std::cout << str << "  =>  " << std::boolalpha << nnf << std::endl;
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