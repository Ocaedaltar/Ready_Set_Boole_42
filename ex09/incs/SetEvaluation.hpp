/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SetEvaluation.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 20:43:41 by mlormois          #+#    #+#             */
/*   Updated: 2022/03/30 11:57:12 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETEVALUATION_HPP
# define SETEVALUATION_HPP

# include <vector>
# include <string>
# include <iostream>
# include <stack>
# include <algorithm>


# include "Ast.hpp"

typedef std::vector<int> Set;
typedef std::vector<Set> Sets;

struct Node
{
	Set		value;
	bool	neg;

	Node( void );
	Node( Set value, bool neg );
	Node( Node const & cpy );
	~Node( void );

	Node &operator=( Node const & other );
	void setNeg( void );
};


# define MAJ_TO_DIG 65

Set eval_set( std::string formula, Sets sets);

#endif