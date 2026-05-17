/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 21:05:01 by cgross-s          #+#    #+#             */
/*   Updated: 2026/05/14 22:27:33 by cgross-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	// Teste com STACK (Pilha)
    std::cout << "Criando zumbi na stack:" << std::endl;
    randomChump("ZumbiStack");
    
    // Teste com HEAP (Monte)
    std::cout << "\nCriando zumbi no heap:" << std::endl;
    Zombie* zumbiHeap = newZombie("ZumbiHeap");
    zumbiHeap->announce();
    delete zumbiHeap;
    
    return 0;
}