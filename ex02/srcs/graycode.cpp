/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graycode.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:41:06 by mlormois          #+#    #+#             */
/*   Updated: 2022/02/25 23:47:15 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graycode.hpp"

unsigned int graycode( unsigned int a )
{
	return (a ^ (a >> 1));
}

// unsigned int adder( unsigned int a, unsigned int b)
// {
// 	if (!a)
// 		return b;
// 	return adder((a & b) << 1, a ^ b);
// }

// unsigned int ft_gtob( unsigned int a )
// {

// 	unsigned int ret;
// 	int i = 31;

// 	while (i >= 0)
// 	{
// 		if (a & (1 << i))
// 			break;
// 		i--;
// 	}

// 	ret = a & (1 << i);

// 	while ( i >= 0 )
// 	{
// 		ret = adder( ret , (ret & ( 1 << (i + 1))) ^ (a & (1 << i)) );
// 		i--;
// 	}
// 	return ret;
// }

void ft_print_bit( unsigned int a )
{
	for ( int i = 7; i >= 0; i--)
		std::cout << ((a & (1 << i)) ? 1 : 0) << (i % 4 == 0 ? " " : "");
}
