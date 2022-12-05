/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adder.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 14:46:12 by mlormois          #+#    #+#             */
/*   Updated: 2022/12/01 12:49:34 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ADDER_HPP
# define ADDER_HPP

# include <string>
# include <iostream>
# include <iomanip>

# define AFFNUM(x) std::setw(5) << x

unsigned int adder( unsigned int a, unsigned int b);

#endif