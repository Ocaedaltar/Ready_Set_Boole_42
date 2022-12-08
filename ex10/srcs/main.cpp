/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 03:28:36 by mlormois          #+#    #+#             */
/*   Updated: 2022/12/08 07:39:17 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include <string>
#include <iostream>
#include <iomanip>

long adder( long a, long b) {
	return (a ? adder((a & b) << 1, a ^ b) : b);
}

long multiplier( long a, long b ) {
	return ( b > 1 ? adder(a, multiplier( a, b - 1 )) : b == 1 ? a : 0);
}

double power( unsigned int elem, unsigned int exp) {
	return (exp > 0 ? multiplier(power(elem, exp - 1), elem) : 1);
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
	return ( (double)ret / power(2, 32) );
}

unsigned short *reverse_map( double n )
{
	unsigned short x, y;
	unsigned int convert;

	x = 0;
	y = 0;

	convert = (unsigned int)(n * power(2, 32));

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

static void ft_visualizer(int x, int y) {

	if (x < 0 || y < 0 || x > 65535 || y > 65535 )
		throw std::out_of_range("");

	double value = map(x,y);
	unsigned short *ret = reverse_map(value);

	std::cout << "      ox: " << std::setw(5) << x << std::endl;
	std::cout << "      oy: " << std::setw(5) << y << std::endl << std::endl;
	std::cout << "ex10: " << value << std::endl << std::endl;
	std::cout << "ex11: rx: " << std::setw(5) << ret[0] << std::endl << "      ry: " << std::setw(5) << ret[1] << std::endl;
}

int main(int ac, char **av)
{
	if (ac != 3)
		return (std::cout << "Error: Two arguments needed\n", 1);
	try {
		ft_visualizer(std::stoi(av[1]), std::stoi(av[2]));
	} catch (std::invalid_argument const &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	} catch (std::out_of_range const &e) {
		return (std::cerr << "Error: arguments out of range" << std::endl, 1);
	}
	std::cout << std::endl;
	return 0;
}