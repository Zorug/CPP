/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 23:45:54 by cgross-s          #+#    #+#             */
/*   Updated: 2026/05/14 23:53:42 by cgross-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
	// Aloca um novo Zombie no HEAP
	Zombie* zombie = new Zombie(name);
	return zombie;  // Retorna o ponteiro para o objeto alocado
}