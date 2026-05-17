/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 21:06:27 by cgross-s          #+#    #+#             */
/*   Updated: 2026/05/14 23:54:08 by cgross-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void randomChump(std::string name)
{
	// Cria um Zombie na STACK
	Zombie zombie(name);
	zombie.announce();
	// Quando a função termina, o destructor é chamado AUTOMATICAMENTE
}