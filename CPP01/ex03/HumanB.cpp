/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 21:42:31 by cgross-s          #+#    #+#             */
/*   Updated: 2026/05/19 20:09:49 by cgross-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

// Construtor - só inicializa o nome
// Ponteiro _weapon começa como NULL (sem arma)
HumanB::HumanB(std::string name) 
    : _name(name), _weapon(NULL) {
    std::cout << _name << " (HumanB) entrou em cena!" << std::endl;
}

HumanB::~HumanB() {
    std::cout << _name << " (HumanB) saiu de cena!" << std::endl;
}

void HumanB::setWeapon(Weapon& weapon) {
    _weapon = &weapon;  // Guarda o ENDEREÇO da weapon
}

void HumanB::attack(void) const {
    // Verifica se tem arma ANTES de usar!
    if (_weapon == NULL) {
        std::cout << _name << " has no weapon to attack!" << std::endl;
        return;
    }
    // Ponteiro precisa de '->' para acessar membros
    std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}