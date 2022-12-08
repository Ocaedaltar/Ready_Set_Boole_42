/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 14:51:08 by mlormois          #+#    #+#             */
/*   Updated: 2022/12/08 02:44:33 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "adder.hpp"

int main(int ac, char **av)
{
	int val1, val2;

	if ( ac != 3 )
		return (ERR_NARG(ac), 1);
	try {
		val1 = std::stoi(av[1]);
		val2 = std::stoi(av[2]);
		std::cout << val1 << " + " << val2 << " = " << adder(val1, val2) << std::endl;
	} catch (std::invalid_argument const &e) {
		return (ERR_ARG, 1);
    } catch (std::out_of_range const &e) {
		return (ERR_RAN, 1);
    }
	return 0;
}