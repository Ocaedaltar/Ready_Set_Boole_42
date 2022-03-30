/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 21:52:14 by mlormois          #+#    #+#             */
/*   Updated: 2022/03/30 13:14:08 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SetEvaluation.hpp"


Node::Node( void ) : value(Set()), neg(false)
{}

Node::Node( Set value, bool neg ) : value(value), neg(neg)
{}

Node::Node( Node const & cpy )
{
	*this = cpy;
}

Node::~Node( void )
{}

Node &Node::operator=( Node const & other )
{
	value = other.value;
	neg = other.neg;
	return *this;
}

void Node::setNeg( void )
{
	neg = ( neg ? false : true );
}
