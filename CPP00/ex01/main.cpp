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

int main()
{
    Contact c; // Cria um objeto chamado c.

    c.setFirstName("Joao");
    c.setLastName("Silva");
    c.setNickname("joca");

    std::cout << c.getFirstName() << std::endl;
    std::cout << c.getLastName() << std::endl;
    std::cout << c.getNickname() << std::endl;

    return 0;
}

/*
PASSO 1

Primeiro faz UMA classe simples.

Nem precisa ser o exercício ainda.

Faz:

atributo name
setName
getName

Até entenderes.

PASSO 2

Depois expande para:

first name
last name
nickname
PASSO 3

Depois cria:

Contact contacts[8];

Aí vais perceber:

“ahhh, o PhoneBook é só um array de objetos”

PASSO 4

Só depois começa:

ADD
SEARCH
EXIT
*/