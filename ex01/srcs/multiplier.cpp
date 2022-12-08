/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiplier.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 17:10:00 by mlormois          #+#    #+#             */
/*   Updated: 2022/12/08 03:14:32 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "multiplier.hpp"

int adder( int a, int b) {
	return (a ? adder((a & b) << 1, a ^ b) : b);
}

int multiplier( int a, int b ) {
	return ( b > 1 ? adder(a, multiplier( a, b - 1 )) : b == 1 ? a : 0);
}