#include <iostream>
#include <iomanip>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
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
    std::string nickname)
{
    contacts[currentIndex].setFirstName(firstName);
    contacts[currentIndex].setLastName(lastName);
    contacts[currentIndex].setNickname(nickname);

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