/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 21:05:49 by cgross-s          #+#    #+#             */
/*   Updated: 2026/05/17 21:53:49 by cgross-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
    // Teste com horde de 5 zumbis
    int N = 5;
    Zombie* horde = zombieHorde(N, "HordeZombie");
    
    // Anuncia todos (aproveita announce do ex00)
    for (int i = 0; i < N; i++) {
        horde[i].announce();
    }
    
    // Libera a horde (DELETE[] - importante os colchetes!)
    delete[] horde;
    
    return 0;
}