/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 04:33:40 by mlormois          #+#    #+#             */
/*   Updated: 2022/12/08 05:35:49 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ast_utils.hpp"
#include "Ast.hpp"

static void ft_visualizer( std::string const & str ) {
	is_rpn( str );
	ft::Ast tree( str );
	std::cout << str << " = " << std::boolalpha << tree.result() << std::endl;
}

int main(int ac, char **av)
{
	for (int i = 1; i < ac; i++) {
		try {
			ft_visualizer(av[i]);
		} catch (std::invalid_argument const &e) {
			std::cerr << "Error: " << av[i] << ' ' << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	return 0;
}