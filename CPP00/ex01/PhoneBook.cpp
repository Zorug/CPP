#include <iostream>
#include "PhoneBook.hpp"

void PhoneBook::test()
{
    contacts[0].setFirstName("Joao");

    std::cout << contacts[0].getFirstName() << std::endl;
}