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
            std::string nickname);

        void showContacts();
};

#endif

/*
O construtor serve para:
- preparar o objeto
- inicializar variáveis
- deixar o objeto pronto para uso
*/