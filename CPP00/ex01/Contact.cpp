/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 22:00:43 by cgross-s          #+#    #+#             */
/*   Updated: 2026/05/08 23:43:02 by cgross-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"


void Contact::setName(std::string value) // “a função setName da classe Contact”
{
    name = value;
}

std::string Contact::getName() // devolve o valor guardado
{
    return name;
}
