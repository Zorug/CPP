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

#include <iostream>
#include <list>
#include "../include/MutantStack.hpp"

int main() {
    // 🧪 Testing MutatedStack
    MutatedStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << "Top element: " << mstack.top() << std::endl;

    mstack.pop();

    std::cout << "Size after pop: " << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutatedStack<int>::iterator it = mstack.begin();
    MutatedStack<int>::iterator ite = mstack.end();

    ++it;
    --it;

    std::cout << "Elements in MutatedStack:" << std::endl;
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }

    // 📋 Testing copy constructor (can be copied into a standard stack)
    std::stack<int> s(mstack);

    return 0;
}