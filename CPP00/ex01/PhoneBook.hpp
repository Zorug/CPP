/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 19:22:44 by cgross-s          #+#    #+#             */
/*   Updated: 2026/05/10 22:04:56 by cgross-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

/*
"Existe uma classe chamada PhoneBook"
"Ela tem estas variáveis e estas funções"
*/
class PhoneBook
{
    private:
        Contact contacts[8];
        int currentIndex; // “onde guardar o próximo contacto”
        int totalContacts; // “quantos contactos existem realmente”

    public:
        // “a classe tem um construtor”
        PhoneBook(); // construtor: Serve para inicializar valores.

        // “existe uma função addContact”
        void addContact(
            std::string firstName,
            std::string lastName,
            std::string nickname,
            std::string phoneNumber,
            std::string darkestSecret);

        void showContacts();
        void displayContact(int index);

        int getTotalContacts();
};

#endif

/*
O construtor serve para:
- preparar o objeto
- inicializar variáveis
- deixar o objeto pronto para uso
*/