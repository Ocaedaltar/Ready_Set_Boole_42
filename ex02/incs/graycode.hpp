/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graycode.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:39:29 by mlormois          #+#    #+#             */
/*   Updated: 2022/12/08 03:55:20 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAYCODE_HPP
# define GRAYCODE_HPP

# include <string>
# include <iostream>

# define ABS(x) ( x < 0 ? -x : x )
# define ERR_NARG(x) std::cerr << "Error: too " << (x < 2 ? "less" : "much" ) << " number of arguments" << std::endl
# define ERR_ARG std::cerr << "Error: bad arguments" << std::endl
# define ERR_RAN std::cerr << "Error: argument out of range" << std::endl

unsigned int gray_code( unsigned int a );

#endif
