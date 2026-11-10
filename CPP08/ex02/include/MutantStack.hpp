/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 14:13:58 by cgross-s          #+#    #+#             */
/*   Updated: 2026/11/10 14:48:45 by cgross-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTATEDSTACK_HPP
#define MUTATEDSTACK_HPP

#include <stack>

template <typename T>
class MutatedStack : public std::stack<T> {
public:
    // 🏗️ Orthodox Canonical Form
    MutatedStack() : std::stack<T>() {}
    MutatedStack(const MutatedStack &other) : std::stack<T>(other) {}
    MutatedStack &operator=(const MutatedStack &other) {
        if (this != &other) {
            std::stack<T>::operator=(other);
        }
        return *this;
    }
    virtual ~MutatedStack() {}

    // 🔄 Iterator definitions
    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;

    // 🧭 Navigation methods
    iterator begin() { return this->c.begin(); }
    iterator end() { return this->c.end(); }

    const_iterator begin() const { return this->c.begin(); }
    const_iterator end() const { return this->c.end(); }
};

#endif