/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 21:42:19 by cgross-s          #+#    #+#             */
/*   Updated: 2026/05/18 23:26:15 by cgross-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

// Construtor - inicializa a referência (obrigatório!)
// Referências DEVEM ser inicializadas na lista de inicialização
HumanA::HumanA(std::string name, Weapon& weapon) 
    : _name(name), _weapon(weapon) {
    // Opcional: mensagem de debug
    // std::cout << _name << " (HumanA) entrou em cena!" << std::endl;
}

HumanA::~HumanA() {
    // Opcional: mensagem de debug
    // std::cout << _name << " (HumanA) saiu de cena!" << std::endl;
}

void HumanA::attack(void) const {
    // Acessa a arma diretamente (é referência, não precisa de ->)
    std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}