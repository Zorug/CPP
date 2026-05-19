/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 21:42:26 by cgross-s          #+#    #+#             */
/*   Updated: 2026/05/19 19:52:04 by cgross-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

//#include <string>
//#include <iostream>
#include "Weapon.hpp"

class HumanA {
private:
    std::string _name;
    Weapon& _weapon;  // REFERÊNCIA - HumanA SEMPRE tem uma arma

public:
    // Construtor OBRIGA a receber uma Weapon (referência não pode ser nula)
    HumanA(std::string name, Weapon& weapon);
    
    // Destrutor
    ~HumanA();
    
    // Member function
    void attack(void) const;
};

#endif