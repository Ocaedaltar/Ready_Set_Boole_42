/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:04:58 by mlormois          #+#    #+#             */
/*   Updated: 2022/12/08 04:08:25 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graycode.hpp"

static std::string ft_print_bit( unsigned int a, unsigned short deep = 8) {
	std::string res = "";
	for ( int i = deep - 1; i >= 0; i--) {
		res.push_back(((a & (1 << i)) ? '1' : '0'));
		if ( i % 4 == 0 && i ) res.push_back(' ');
	}
	return res;
}

static void ft_visual_uitogc( unsigned int a )
{
	unsigned int gray = gray_code(a);
	std::cout << "        " << a << "  =>  " << gray << std::endl;
	std::cout << ft_print_bit(a) << "  =>  " << ft_print_bit(gray);
	std::cout << std::endl << std::endl;
}

int main(int ac, char **av)
{
	int val;

	if (ac == 1)
		return (ERR_NARG(ac), 1);
	for (int i = 1; i < ac; i++) {
		try {
			if ((val = std::stoi(av[i])) < 0) {
				std::cout << "Error: " << av[i] << ", negatif not required in the subject" << std::endl << std::endl;
			} else {
				ft_visual_uitogc(val);
			}
		} catch (std::invalid_argument const &e) {
			std::cerr << "Error: " << av[i] << " is bad arguments" << std::endl << std::endl;
		} catch (std::out_of_range const &e) {
			std::cerr << "Error: " << av[i] << " is out of range" << std::endl << std::endl;
		}
	}
	return 0;
}