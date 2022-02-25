/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:04:58 by mlormois          #+#    #+#             */
/*   Updated: 2022/02/25 23:48:59 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graycode.hpp"

void test( unsigned int a )
{
	unsigned int gray = graycode(a);
	std::cout << a <<  " in graycode: " << graycode(a) << std::endl;
	ft_print_bit(a);
	std::cout << " ----> ";
	ft_print_bit( gray );
	// std::cout << " ----> ";
	// ft_print_bit( ft_gtob(gray) );
	// std::cout << "  soit: " << a << " = " << gray << " = " << ft_gtob(gray) << std::endl;
	std::cout << std::endl;
}

int main( void )
{
	for (unsigned int i = 0; i < 20; i++)
		test(i);
}