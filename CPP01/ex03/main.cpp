/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 21:42:42 by cgross-s          #+#    #+#             */
/*   Updated: 2026/05/18 23:35:48 by cgross-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	Objetivo:
	mostrar a diferença entre referência e ponteiro como membros de classe*/

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main() {
    {
        Weapon club = Weapon("crude spiked club");
        
        HumanA bob("Bob", club);
        bob.attack();
        
        club.setType("some other type of club");
        bob.attack();
    }
    {
        Weapon club = Weapon("crude spiked club");
        
        HumanB jim("Jim");
        jim.setWeapon(club);
        jim.attack();
        
        club.setType("some other type of club");
        jim.attack();
    }
    
    return 0;
}