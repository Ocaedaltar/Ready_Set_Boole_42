/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiplier.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 17:10:00 by mlormois          #+#    #+#             */
/*   Updated: 2022/02/25 18:00:20 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "multiplier.hpp"

// RECURSIVE
unsigned int adder( unsigned int a, unsigned int b)
{
	if (!a)
		return b;
	return adder((a & b) << 1, a ^ b);
}

unsigned int multiplier( unsigned int a, unsigned int b )
{
	if (b == 1)
		return a;
	else if (b > 1)
		return ( adder(a, multiplier( a, b - 1 )) );
	return 0;
}
