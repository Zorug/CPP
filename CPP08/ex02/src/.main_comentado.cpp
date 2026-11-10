/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 14:14:56 by cgross-s          #+#    #+#             */
/*   Updated: 2026/11/10 14:48:43 by cgross-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Teste do ex02, baseado no exemplo do subject.
** Objetivo: provar que a stack continua a funcionar como stack
** (push/pop/top/size) E que agora também se pode percorrer com iteradores.
*/

#include <iostream>
#include <list>      /* usado só se quiseres comparar com std::list */
#include "../include/MutantStack.hpp"

int main() {
    /* ==================================================================== */
    /*  1. OPERAÇÕES NORMAIS DE STACK (herdadas de std::stack)              */
    /* ==================================================================== */
    MutatedStack<int> mstack;

    mstack.push(5);     /* stack: 5 */
    mstack.push(17);    /* stack: 5, 17 */

    /* top() devolve o último elemento inserido (sem o remover): 17 */
    std::cout << "Top element: " << mstack.top() << std::endl;

    mstack.pop();       /* remove o topo (17) -> stack: 5 */

    /* Só resta o 5, logo size() = 1 */
    std::cout << "Size after pop: " << mstack.size() << std::endl;

    mstack.push(3);     /* stack: 5, 3 */
    mstack.push(5);     /* stack: 5, 3, 5 */
    mstack.push(737);   /* stack: 5, 3, 5, 737 */
    mstack.push(0);     /* stack: 5, 3, 5, 737, 0 */

    /* ==================================================================== */
    /*  2. ITERADORES (a funcionalidade nova)                               */
    /* ==================================================================== */

    /* begin() aponta para o fundo da stack, end() para "depois do topo". */
    MutatedStack<int>::iterator it = mstack.begin();
    MutatedStack<int>::iterator ite = mstack.end();

    /*
    ** ++it e --it: teste rápido de que o iterador é bidirecional
    ** (avança e recua). Voltamos à posição inicial.
    */
    ++it;
    --it;

    /*
    ** Percorremos do fundo para o topo até 'it' chegar a 'ite'.
    ** Saída esperada: 5, 3, 5, 737, 0 (uma por linha).
    ** Idêntica à que obterias com std::list (usando push_back).
    */
    std::cout << "Elements in MutatedStack:" << std::endl;
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }

    /* ==================================================================== */
    /*  3. COMPATIBILIDADE COM std::stack                                   */
    /* ==================================================================== */

    /*
    ** Como MutatedStack HERDA PUBLICAMENTE de std::stack<int>, podemos
    ** construir uma std::stack<int> a partir dela (o objeto é "fatiado"
    ** para a parte base). Se compilar, a herança está correta.
    */
    std::stack<int> s(mstack);

    return 0;
}
