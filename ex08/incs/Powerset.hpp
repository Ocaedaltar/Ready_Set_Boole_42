/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Powerset.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:01:58 by mlormois          #+#    #+#             */
/*   Updated: 2022/03/16 19:22:10 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POWERSET_HPP
# define POWERSET_HPP

# include <vector>
# include <math.h>
# include <string>
# include <iostream>

void print_vector( std::vector<int> set );
std::vector<std::vector<int>> powerset( std::vector<int> set );
void print_powerset( std::vector<int> set, std::vector<std::vector<int>> powset );

#endif