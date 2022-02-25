/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 17:01:50 by mlormois          #+#    #+#             */
/*   Updated: 2022/02/25 17:33:40 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "multiplier.hpp"

void test( unsigned int a , unsigned int b)
{
	std::cout << a << " x " << b << " = " << multiplier(a, b) << std::endl;
}

int main( void )
{
	test(9, 10);
	test(5, 2);
	test(42, 0);
	test(1, 1000);
	test(13, 238);
	return 0;
}