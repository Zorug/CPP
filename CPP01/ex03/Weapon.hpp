/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 21:42:52 by cgross-s          #+#    #+#             */
/*   Updated: 2026/05/18 22:33:23 by cgross-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon {
private:
    std::string _type;

public:
    // Construtor
    Weapon(std::string type);
    
    // Destrutor
    ~Weapon();
    
    // Getter - retorna CONST reference (não pode modificar)
    const std::string& getType(void) const;
    
    // Setter - modifica o tipo
    void setType(std::string newType);
};

#endif