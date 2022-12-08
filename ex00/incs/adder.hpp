/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adder.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 14:46:12 by mlormois          #+#    #+#             */
/*   Updated: 2022/12/08 02:42:55 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ADDER_HPP
# define ADDER_HPP

# include <string>
# include <iostream>
# include <iomanip>

# define ERR_NARG(x) std::cerr << "Error: too " << (x < 2 ? "less" : "much" ) << " number of arguments" << std::endl
# define ERR_ARG std::cerr << "Error: bad arguments" << std::endl
# define ERR_RAN std::cerr << "Error: argument out of range" << std::endl

int adder( int a, int b);

#endif