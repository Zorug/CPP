/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_commited.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 14:14:56 by cgross-s          #+#    #+#             */
/*   Updated: 2026/11/10 14:59:57 by cgross-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Test for ex02, based on the subject example.
** Objective: prove that the stack still works as a stack
** (push/pop/top/size) AND that it can now also be traversed with iterators.
*/

#include <iostream>
#include <list>      /* used only if you want to compare with std::list */
#include "../include/MutantStack.hpp"

int main() {
    /* ==================================================================== */
    /*  1. NORMAL STACK OPERATIONS (inherited from std::stack)              */
    /* ==================================================================== */
    MutatedStack<int> mstack;

    mstack.push(5);     /* stack: 5 */
    mstack.push(17);    /* stack: 5, 17 */

    /* top() returns the last inserted element (without removing it): 17 */
    std::cout << "Top element: " << mstack.top() << std::endl;

    mstack.pop();       /* removes the top element (17) -> stack: 5 */

    /* Only 5 remains, so size() = 1 */
    std::cout << "Size after pop: " << mstack.size() << std::endl;

    mstack.push(3);     /* stack: 5, 3 */
    mstack.push(5);     /* stack: 5, 3, 5 */
    mstack.push(737);   /* stack: 5, 3, 5, 737 */
    mstack.push(0);     /* stack: 5, 3, 5, 737, 0 */

    /* ==================================================================== */
    /*  2. ITERATORS (the new functionality)                                */
    /* ==================================================================== */

    /* begin() points to the bottom of the stack, end() points to "past the top". */
    MutatedStack<int>::iterator it = mstack.begin();
    MutatedStack<int>::iterator ite = mstack.end();

    /*
    ** ++it and --it: quick test that the iterator is bidirectional
    ** (can advance and go back). We return to the initial position.
    */
    ++it;
    --it;

    /*
    ** Traverse from bottom to top until 'it' reaches 'ite'.
    ** Expected output: 5, 3, 5, 737, 0 (one per line).
    ** Identical to what you would get with std::list (using push_back).
    */
    std::cout << "Elements in MutatedStack:" << std::endl;
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }

    /* ==================================================================== */
    /*  3. COMPATIBILITY WITH std::stack                                   */
    /* ==================================================================== */

    /*
    ** Since MutatedStack PUBLICLY INHERITS from std::stack<int>, we can
    ** construct a std::stack<int> from it (the object is sliced down
    ** to the base part). If it compiles, the inheritance is correct.
    */
    std::stack<int> s(mstack);

    return 0;
}