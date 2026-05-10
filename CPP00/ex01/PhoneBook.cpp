/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 19:22:33 by cgross-s          #+#    #+#             */
/*   Updated: 2026/05/10 21:42:53 by cgross-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip> // formatar a tabela
#include "PhoneBook.hpp"

PhoneBook::PhoneBook() //constructor
{
    currentIndex = 0;
    totalContacts = 0;
}

std::string formatField(std::string str)
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";

    return str;
}

void PhoneBook::addContact(
    std::string firstName,
    std::string lastName,
    std::string nickname,
    std::string phoneNumber,
    std::string darkestSecret)
{
    contacts[currentIndex].setFirstName(firstName);
    contacts[currentIndex].setLastName(lastName);
    contacts[currentIndex].setNickname(nickname);
    contacts[currentIndex].setPhoneNumber(phoneNumber);
    contacts[currentIndex].setDarkestSecret(darkestSecret);

    currentIndex = (currentIndex + 1) % 8;

    if (totalContacts < 8)
        totalContacts++;
}

void PhoneBook::showContacts()
{
    std::cout << std::setw(10) << "Index" << "|";
    std::cout << std::setw(10) << "First Name" << "|";
    std::cout << std::setw(10) << "Last Name" << "|";
    std::cout << std::setw(10) << "Nickname" << std::endl;

    for (int i = 0; i < totalContacts; i++)
    {
        std::cout << std::setw(10) << i << "|";

        std::cout << std::setw(10)
                  << formatField(contacts[i].getFirstName()) << "|";

        std::cout << std::setw(10)
                  << formatField(contacts[i].getLastName()) << "|";

        std::cout << std::setw(10)
                  << formatField(contacts[i].getNickname()) << std::endl;
    }
}

void PhoneBook::displayContact(int index)
{
    std::cout << "First name: "
              << contacts[index].getFirstName() << std::endl;

    std::cout << "Last name: "
              << contacts[index].getLastName() << std::endl;

    std::cout << "Nickname: "
              << contacts[index].getNickname() << std::endl;

    std::cout << "Phone number: "
              << contacts[index].getPhoneNumber() << std::endl;

    std::cout << "Darkest secret: "
              << contacts[index].getDarkestSecret() << std::endl;
}