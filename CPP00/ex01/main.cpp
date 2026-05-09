/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 22:00:34 by cgross-s          #+#    #+#             */
/*   Updated: 2026/05/08 23:45:54 by cgross-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"
#include "PhoneBook.hpp"

int main()
{
    // aqui já é criado o construtor
    PhoneBook pb;

    std::string command;

    while (true) // Loop infinito.
    {
        std::cout << "Enter command: ";

        std::getline(std::cin, command);

        if (command == "ADD")
        {
            // Criar variáveis temporárias
            std::string firstName;
            std::string lastName;
            std::string nickname;

            // Ler input
            std::cout << "First name: ";
            std::getline(std::cin, firstName);

            std::cout << "Last name: ";
            std::getline(std::cin, lastName);

            std::cout << "Nickname: ";
            std::getline(std::cin, nickname);

            // Enviar para o PhoneBook
            pb.addContact(firstName, lastName, nickname);
        }
        else if (command == "SEARCH")
        {
            pb.showContacts();
        }
        else if (command == "EXIT")
        {
            break;
        }
    }

    return 0;
}
