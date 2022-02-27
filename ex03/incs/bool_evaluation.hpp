/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bool_evaluation.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 15:01:49 by mlormois          #+#    #+#             */
/*   Updated: 2022/02/27 15:52:51 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOOL_EVALUATION_HPP
# define BOOL_EVALUATION_HPP

# include <string>
# include <iostream>

# define MSG( str ) std::cout << str << std::endl;

bool eval_formula( std::string formula );

#endif