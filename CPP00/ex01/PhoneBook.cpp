#include <iostream>
#include "PhoneBook.hpp"

// primeiro construtor
// "esta função pertence à classe PhoneBook"
PhoneBook::PhoneBook()
{
    currentIndex = 0;
    totalContacts = 0;
}

void PhoneBook::addContact(
    std::string firstName,
    std::string lastName,
    std::string nickname)
{
    contacts[currentIndex].setFirstName(firstName);
    contacts[currentIndex].setLastName(lastName);
    contacts[currentIndex].setNickname(nickname);

    // Se currentIndex = 7 -> Volta ao início.
    currentIndex = (currentIndex + 1) % 8;

    if (totalContacts < 8)
        totalContacts++;
}

void PhoneBook::showContacts()
{
    for (int i = 0; i < totalContacts; i++)
    {
        std::cout << i << " ";

        std::cout << contacts[i].getFirstName() << " ";

        std::cout << contacts[i].getLastName() << " ";

        std::cout << contacts[i].getNickname() << std::endl;
    }
}