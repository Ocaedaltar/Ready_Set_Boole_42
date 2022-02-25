/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adder.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 14:44:25 by mlormois          #+#    #+#             */
/*   Updated: 2022/02/25 16:05:29 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "adder.hpp"

unsigned int adder( unsigned int a, unsigned int b)
{
	if (!a)
		return b;
	return adder((a & b) << 1, a ^ b);
}

// Pour respecter la contrainte O(1), on nous force la recursion. 
// Ainsi la fonction est bien O(1), losque le calcule ne l'est pas.

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
