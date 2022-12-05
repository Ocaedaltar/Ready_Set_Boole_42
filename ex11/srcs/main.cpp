/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 03:28:36 by mlormois          #+#    #+#             */
/*   Updated: 2022/12/05 17:59:17 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include <string>
#include <iostream>

void print_long_bits( unsigned int value, std::string name )
{
  	std::cout << name << ": ";
	for ( int i = 31; i >= 0; i--)
		std::cout << ((value & (1 << i)) == false ? '0' : '1');
  	std::cout << std::endl;
}

double map( unsigned short x, unsigned short y )
{
	unsigned int ret, fx, fy;
	ret = 0;

	for ( int i = 15; i >= 0; i--)
	{
		fx = (x & 1 << i) ? (1 << (i * 2)) : 0;
		fy = (y & 1 << i) ? 1 << (i * 2 + 1) : 0;
		ret += fx + fy;
	}
	return ( (double)ret / std::pow(2, 32) );
}

unsigned short *reverse_map( double n )
{
	unsigned short x, y;
	unsigned int convert;

	x = 0;
	y = 0;

	convert = (unsigned int)(n * std::pow(2, 32));

	for ( int i = 15; i >= 0; i--)
	{
		x += ( convert & 1 << (i * 2) ) >> i;
		y += ( convert & 1 << (i * 2 + 1) ) >> (i + 1);
	}

	unsigned short *ret = new unsigned short[2];
	ret[0] = x;
	ret[1] = y;
	return (ret);
}

void print_bits( short value, std::string name )
{
	std::cout << name << ": ";
	for ( int i = 15; i >= 0; i--)
		std::cout << ((value & (1 << i)) == false ? '0' : '1');
	std::cout << std::endl;
}

int main( void )
{
	unsigned short x, y;
	double n = 0;

	x = 1;
	y = 2;

	n = map( x, y );
	std::cout << std::endl << "n: " << n << std::endl;
	
	unsigned short *ret = reverse_map(n);
	std::cout << "x: " << ret[0] << std::endl << "y: " << ret[1] << std::endl;
}
