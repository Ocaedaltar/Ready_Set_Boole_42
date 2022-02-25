/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adder.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 14:44:25 by mlormois          #+#    #+#             */
/*   Updated: 2022/02/25 17:41:04 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "adder.hpp"

// RECURSIVE
// unsigned int adder( unsigned int a, unsigned int b)
// {
// 	if (!a)
// 		return b;
// 	return adder((a & b) << 1, a ^ b);
// }

// ITERATIVE
unsigned int adder( unsigned int a, unsigned int b)
{
	unsigned int tmp;
	while (a && b)
	{
		tmp = (a & b) << 1;
		b = a ^ b;
		a = tmp;
	}
	return b;
}

// exemple pour 3 + 1 = 4

// ONE
//   000011
// & 000001
//<< 000001
//   000010

//   000011
// ^ 000001
//   000010

// TWO
//   000010
// & 000010
//<< 000010
//   000100

//   000010
// ^ 000010
//   000000
