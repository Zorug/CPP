/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 22:00:34 by cgross-s          #+#    #+#             */
/*   Updated: 2026/05/10 21:40:11 by cgross-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "PhoneBook.hpp"

int main()
{
    PhoneBook pb;

    std::string command;

    while (true)
    {
        std::cout << "Enter command: ";

        std::getline(std::cin, command);

        if (command == "ADD")
        {
            std::string firstName;
            std::string lastName;
            std::string nickname;
            std::string phoneNumber;
            std::string darkestSecret;

            std::cout << "First name: ";
            std::getline(std::cin, firstName);

            std::cout << "Last name: ";
            std::getline(std::cin, lastName);

            std::cout << "Nickname: ";
            std::getline(std::cin, nickname);

            std::cout << "Phone number: ";
            std::getline(std::cin, phoneNumber);

            std::cout << "Darkest secret: ";
            std::getline(std::cin, darkestSecret);

            pb.addContact(
                firstName,
                lastName,
                nickname,
                phoneNumber,
                darkestSecret);
        }
        else if (command == "SEARCH")
        {
            pb.showContacts();

            std::string input;

            std::cout << "Choose index: ";

            std::getline(std::cin, input);

            int index = input[0] - '0';

            if (input.length() == 1
                && index >= 0
                && index < 8)
            {
                pb.displayContact(index);
            }
            else
            {
                std::cout << "Invalid index" << std::endl;
            }
        }
        else if (command == "EXIT")
        {
            break;
        }
    }

    return 0;
}