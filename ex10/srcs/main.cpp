/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 20:12:16 by mlormois          #+#    #+#             */
/*   Updated: 2022/03/31 21:33:23 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

float map( short x, short y )
{
    float ret, fx, fy;
    ret = 0;

    for ( int i = 0; i < 16; i++)
    {
        fx = (x & 1 << i);
        fy = (y & 1 << i) << 1;
        ret += fx + fy;
    }

    long  convert = *(long*)&ret ;
    convert  = 0x5f3759df - ( convert >> 32 ); 
    ret = *(float*)&convert;

    return (ret);
}

int16_t *reverse_map( float n )
{
    int16_t x, y;

    x = 0;
    y = 0;

    long convert = *(long*)&n;

    for ( int i = 0; i < 16; i++)
    {
        x += ( convert & 1 << (i * 2) ) >> i;
        y += ( convert & 1 << (i * 2 + 1) ) >> i;
    }

    int16_t *ret = new int16_t[2];
    ret[0] = x;
    ret[1] = y;
    return (ret);
}

int main( void )
{
    short x, y;
    float n;

    x = 900;
    y = 20;
    std::cout << "map: " << (n = map( x, y )) << std::endl;

    int16_t *ret = reverse_map(n);
    std::cout << "x: " << ret[0] << std::endl << "y: " << ret[1] << std::endl;
}