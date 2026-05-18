/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 20:33:29 by cgross-s          #+#    #+#             */
/*   Updated: 2026/05/18 21:23:13 by cgross-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream> // imprimir na tela e ler entrada
#include <string> // manipular texto

/*	Objetivo: mostrar que ponteiros e referências fazem a mesma coisas
	É como se fosse um apelido para a variável apontada*/

int main() {
    // 1. VARIÁVEL NORMAL
    std::string str = "HI THIS IS BRAIN";
    
    // 2. PONTEIRO - guarda o ENDEREÇO de str
    std::string* stringPTR = &str;
    
    // 3. REFERÊNCIA - é um APELIDO para str
    std::string& stringREF = str;
    
    // ============================================
    // PARTE 1: Imprimir os endereços
    // ============================================
    
    // Endereço da variável str
    std::cout << "Endereço de str:      " << &str << std::endl;
    
    // Valor guardado no ponteiro (que é o endereço de str)
    std::cout << "Endereço em stringPTR: " << stringPTR << std::endl;
    
    // Endereço da referência (que é o mesmo de str)
    std::cout << "Endereço em stringREF: " << &stringREF << std::endl;
    
    // TODOS OS TRÊS SÃO IGUAIS!
    
    // ============================================
    // PARTE 2: Imprimir os valores
    // ============================================
    
    // Valor direto da variável
    std::cout << "Valor de str:         " << str << std::endl;
    
    // Ponteiro: precisa de * para acessar o valor
    std::cout << "Valor apontado por PTR:" << *stringPTR << std::endl;
    
    // Referência: usa diretamente (é a própria variável)
    std::cout << "Valor apontado por REF:" << stringREF << std::endl;
    
    // TODOS OS TRÊS SÃO IGUAIS!
    
    return 0;
}