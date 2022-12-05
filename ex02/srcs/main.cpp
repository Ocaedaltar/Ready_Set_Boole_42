/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:04:58 by mlormois          #+#    #+#             */
/*   Updated: 2022/12/05 17:18:30 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graycode.hpp"

void test( unsigned int a )
{
	unsigned int gray = gray_code(a);
	std::cout << a <<  " in graycode: " << gray_code(a) << std::endl;
	ft_print_bit(a);
	std::cout << " ----> ";
	ft_print_bit( gray );
	std::cout << std::endl << std::endl;
}

int main( void )
{
	// for (unsigned int i = 0; i < 20; i++)
	// 	test(i);

	std::cout <<  gray_code(2) << std::endl;
	std::cout <<  gray_code(3) << std::endl;
	std::cout <<  gray_code(4) << std::endl;
	std::cout <<  gray_code(5) << std::endl;
	std::cout <<  gray_code(6) << std::endl;
	std::cout <<  gray_code(7) << std::endl;
	std::cout <<  gray_code(8) << std::endl;
}