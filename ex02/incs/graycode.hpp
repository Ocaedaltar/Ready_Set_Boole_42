/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graycode.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:39:29 by mlormois          #+#    #+#             */
/*   Updated: 2022/12/01 13:07:04 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAYCODE_HPP
# define GRAYCODE_HPP

# include <string>
# include <iostream>

void ft_print_bit( unsigned int a );
unsigned int gray_code( unsigned int a );

#endif

// FORMULA:
// g(i) = b(i) ^ b(i-1)