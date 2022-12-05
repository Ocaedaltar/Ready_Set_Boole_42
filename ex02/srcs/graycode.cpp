/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graycode.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:41:06 by mlormois          #+#    #+#             */
/*   Updated: 2022/12/01 13:06:50 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graycode.hpp"

unsigned int gray_code( unsigned int a )
{
	return (a ^ (a >> 1));
}

void ft_print_bit( unsigned int a )
{
	for ( int i = 7; i >= 0; i--)
		std::cout << ((a & (1 << i)) ? 1 : 0) << (i % 4 == 0 ? " " : "");
}
