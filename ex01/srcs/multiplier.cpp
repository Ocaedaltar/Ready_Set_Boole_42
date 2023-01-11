/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiplier.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 17:10:00 by mlormois          #+#    #+#             */
/*   Updated: 2023/01/11 14:56:38 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "multiplier.hpp"

int adder( int a, int b)
{
	int tmp;
	while (a)
	{
		tmp = (a & b) << 1;
		b = a ^ b;
		a = tmp;
	}
	return b;
}

int multiplier( int a, int b ) {
    int max = ~0U >> 1, res = 0;

    for (int i = 31; i >= 0; i--)
        if ( a & 1 << i )
            { res = adder(res, b << i ); }
    return res;
}