/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   negation.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:43:30 by mlormois          #+#    #+#             */
/*   Updated: 2022/12/05 17:23:05 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NEGATION_HPP
# define NEGATION_HPP

# include <stack>
# include <string>
# include <iostream>

# define SPACE std::endl << std::endl
# define ARG_ERR "Error: Invalide Number of Arguments."
# define ERROR( msg ) std::cerr << msg << std::endl;

# include "Ast.hpp"

enum type
{
	VAL = 0,
	AND,
	OR,
	XOR,
	MC,
	EGAL
};

#endif