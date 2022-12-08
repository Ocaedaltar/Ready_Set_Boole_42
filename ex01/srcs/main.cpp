/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 17:01:50 by mlormois          #+#    #+#             */
/*   Updated: 2022/12/08 03:07:20 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "multiplier.hpp"

int main(int ac, char **av)
{
	int val1, val2;

	if ( ac != 3 )
		return (ERR_NARG(ac), 1);
	try {
		val2 = std::stoi(av[2]);
		val1 = std::stoi(av[1]);
		std::cout << val1 << " * " << val2 << " = " << multiplier((val1 * ( val2 < 0 ? -1 : 1)), ABS(val2)) << std::endl;
	}
	catch (std::invalid_argument const &e) { return (ERR_ARG, 1); }
	catch (std::out_of_range const &e) { return (ERR_RAN, 1); }
	return 0;
}