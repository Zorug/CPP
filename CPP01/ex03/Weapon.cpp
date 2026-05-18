/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 21:42:47 by cgross-s          #+#    #+#             */
/*   Updated: 2026/05/18 22:56:15 by cgross-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

// Construtor - inicializa o tipo
Weapon::Weapon(std::string type) : _type(type) {
    std::cout << "Arma " << _type << " criada!" << std::endl;
}

// Destrutor
Weapon::~Weapon() {
    std::cout << "Arma " << _type << " destruída!" << std::endl;
}

// Getter - retorna referência CONSTANTE para _type
// O 'const' no final significa que não modifica o objeto
// O 'const' no retorno significa que quem chama não pode modificar
/*
Por que const reference?
    ✅ Eficiente: não copia a string
    ✅ Seguro: quem chama não pode modificar o tipo da arma
    ✅ Consistente: com o que o subject pede
*/
const std::string& Weapon::getType(void) const {
    return _type;
}

// Setter - modifica o tipo
void Weapon::setType(std::string newType) {
    _type = newType;
}