/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiplier.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 17:08:36 by mlormois          #+#    #+#             */
/*   Updated: 2022/12/08 03:05:02 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MULTIPLIER_HPP
# define MULTIPLIER_HPP

# include <string>
# include <iostream>

# define ABS(x) ( x < 0 ? -x : x )
# define ERR_NARG(x) std::cerr << "Error: too " << (x < 2 ? "less" : "much" ) << " number of arguments" << std::endl
# define ERR_ARG std::cerr << "Error: bad arguments" << std::endl
# define ERR_RAN std::cerr << "Error: argument out of range" << std::endl

int adder( int a, int b);
int multiplier( int a, int b );

#endif