/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 22:00:34 by cgross-s          #+#    #+#             */
/*   Updated: 2026/05/10 22:03:32 by cgross-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "PhoneBook.hpp"

std::string getInput(std::string prompt)
{
    std::string input;

    while (input.empty())
    {
        std::cout << prompt;

        if (!std::getline(std::cin, input))
            return "";

        if (input.empty())
            std::cout << "Field cannot be empty." << std::endl;
    }

    return input;
}

int main()
{
    PhoneBook pb;

    std::string command;

    while (true)
    {
        std::cout << "Enter command: ";

        if (!std::getline(std::cin, command))
            break;

        if (command == "ADD")
        {
            std::string firstName;
            std::string lastName;
            std::string nickname;
            std::string phoneNumber;
            std::string darkestSecret;

            firstName = getInput("First name: ");
            if (firstName.empty())
                break;

            lastName = getInput("Last name: ");
            if (lastName.empty())
                break;

            nickname = getInput("Nickname: ");
            if (nickname.empty())
                break;

            phoneNumber = getInput("Phone number: ");
            if (phoneNumber.empty())
                break;

            darkestSecret = getInput("Darkest secret: ");
            if (darkestSecret.empty())
                break;

            pb.addContact(
                firstName,
                lastName,
                nickname,
                phoneNumber,
                darkestSecret);
        }
        else if (command == "SEARCH")
        {
            if (pb.getTotalContacts() == 0)
            {
                std::cout << "PhoneBook is empty." << std::endl;
                continue;
            }

            pb.showContacts();

            std::string input;

            std::cout << "Choose index: ";

            if (!std::getline(std::cin, input))
                break;

            if (input.length() != 1
                || input[0] < '0'
                || input[0] > '7')
            {
                std::cout << "Invalid index." << std::endl;
                continue;
            }

            int index = input[0] - '0';

            if (index >= pb.getTotalContacts())
            {
                std::cout << "Index does not exist." << std::endl;
                continue;
            }

            pb.displayContact(index);
        }
        else if (command == "EXIT")
        {
            break;
        }
        else
        {
            std::cout << "Invalid command." << std::endl;
        }
    }

    return 0;
}