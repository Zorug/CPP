/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 22:00:43 by cgross-s          #+#    #+#             */
/*   Updated: 2026/05/10 21:38:39 by cgross-s         ###   ########.fr       */
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

void Contact::setPhoneNumber(std::string value)
{
    phoneNumber = value;
}

void Contact::setDarkestSecret(std::string value)
{
    darkestSecret = value;
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

std::string Contact::getPhoneNumber()
{
    return phoneNumber;
}

std::string Contact::getDarkestSecret()
{
    return darkestSecret;
}