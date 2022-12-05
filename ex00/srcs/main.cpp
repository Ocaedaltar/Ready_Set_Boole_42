/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 14:51:08 by mlormois          #+#    #+#             */
/*   Updated: 2022/12/01 12:53:55 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "adder.hpp"

void test( unsigned int a , unsigned int b)
{
	std::cout << AFFNUM(a) << " + " << AFFNUM(b) << " = " << adder(a, b) << std::endl;
}

int main( void )
{
	test(20, 900);
	test(0, 5);
	test(99999, 1);
	test(0, 0);
	return 0;
}