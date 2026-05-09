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

void Contact::setFirstName(std::string value)
{
    firstName = value;
}

void Contact::setLastName(std::string value)
{
    lastName = value;
}

void Contact::setNickname(std::string value)
{
    nickname = value;
}

std::string Contact::getFirstName()
{
    return firstName;
}

std::string Contact::getLastName()
{
    return lastName;
}

std::string Contact::getNickname()
{
    return nickname;
}
