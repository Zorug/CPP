/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 10:07:52 by cgross-s          #+#    #+#             */
/*   Updated: 2026/05/20 10:56:30 by cgross-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
    //std::cout << "Harl created" << std::endl;
}

Harl::~Harl(void)
{
    //std::cout << "Harl destroyed" << std::endl;
}

void Harl::debug(void)
{
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;    
}

void Harl::info(void)
{
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;    
}

void Harl::warning(void)
{
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;    
}

void Harl::error(void)
{
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;    
}

void Harl::complain(std::string level) {
    // Array com os níveis possíveis
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    // Array de ponteiros para member functions
    void (Harl::*functions[4])(void) = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };

    // Procura o nível correspondente
    for (int i = 0; i < 4; i++) {
        if (level == levels[i]) {
            // Chama a função correspondente
            (this->*functions[i])();
            return;
        }
    }

    // Se o nível não for encontrado, imprime uma mensagem de erro
    std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}