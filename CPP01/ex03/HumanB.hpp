/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 21:42:36 by cgross-s          #+#    #+#             */
/*   Updated: 2026/05/18 23:27:25 by cgross-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanB {
private:
    std::string _name;
    Weapon* _weapon;  // PONTEIRO - HumanB PODE não ter arma

public:
    // Construtor só recebe o nome (arma é opcional)
    HumanB(std::string name);
    
    // Destrutor
    ~HumanB();
    
    // Setter para a arma (pode ser chamado a qualquer momento)
    void setWeapon(Weapon& weapon);
    
    // Member function
    void attack(void) const;
};

#endif