/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 21:05:59 by cgross-s          #+#    #+#             */
/*   Updated: 2026/05/17 21:53:25 by cgross-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
    if (N <= 0)
        return NULL;
    
    // Aloca N zumbis de UMA VEZ (aproveita o construtor padrão)
    Zombie* horde = new Zombie[N];
    
    // Nomeia cada um (aproveita o setName)
    for (int i = 0; i < N; i++) {
        horde[i].setName(name);
    }
    
    return horde;
}