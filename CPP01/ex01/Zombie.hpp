/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 21:05:55 by cgross-s          #+#    #+#             */
/*   Updated: 2026/05/17 21:47:13 by cgross-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP 

#include <string>
#include <iostream>

class Zombie
{
	private:
		std::string _name;
	public:
        Zombie();
		Zombie(std::string name);
		~Zombie();
		void announce(void);
        void setName(std::string name);
};

Zombie* zombieHorde(int N, std::string name);

# endif