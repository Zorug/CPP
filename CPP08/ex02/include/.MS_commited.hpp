/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .MS_commited.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 14:13:58 by cgross-s          #+#    #+#             */
/*   Updated: 2026/11/10 15:00:38 by cgross-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ex02 - Mutated abomination
**
** std::stack is a "container adapter": underneath it stores data in
** another container (by default, std::deque) but only exposes push/pop/top/size/
** empty. It lacks begin()/end(), so it is not iterable.
**
** EXERCISE TRICK: the internal container is a PROTECTED member called
** 'c'. If we inherit from std::stack, we have access to 'c' and can expose its
** iterators. We end up with a normal stack + begin()/end().
*/

/* INCLUDE GUARDS: prevent multiple inclusion. */
#ifndef MUTATEDSTACK_HPP
#define MUTATEDSTACK_HPP

/* <stack> provides std::stack (and, indirectly, the default container). */
#include <stack>

/*
** PUBLIC INHERITANCE from std::stack<T>
**   -> MutatedStack inherits ALL functions (push, pop, top, size, empty...),
**      so we fulfill the "offer all its member functions" requirement of the subject
**      without rewriting anything.
**   -> Being public, a MutatedStack "is a" std::stack, and can be
**      converted/copied to a std::stack (see the main test).
*/
template <typename T>
class MutatedStack : public std::stack<T> {
public:
    /* ---------------------------------------------------------------- */
    /*  ORTHODOX CANONICAL FORM                                          */
    /*  Since it's a template, everything goes in the header (allowed).  */
    /* ---------------------------------------------------------------- */

    /* Default constructor: constructs the empty base stack. */
    MutatedStack() : std::stack<T>() {}

    /* Copy constructor: passes 'other' to the base, which copies the internal
    ** container 'c' (deep copy performed by the container itself). */
    MutatedStack(const MutatedStack &other) : std::stack<T>(other) {}

    /*
    ** Assignment operator: protects against self-assignment and delegates
    ** the copy to the base class version.
    ** We write std::stack<T>::operator=(other) explicitly to
    ** call the BASE operator (otherwise there would be infinite recursion).
    */
    MutatedStack &operator=(const MutatedStack &other) {
        if (this != &other) {
            std::stack<T>::operator=(other);
        }
        return *this;
    }

    /*
    ** Virtual destructor: good practice in classes designed for inheritance.
    ** (Note: std::stack has a non-virtual destructor, so here it is
    ** harmless but not essential.)
    */
    virtual ~MutatedStack() {}

    /* ---------------------------------------------------------------- */
    /*  ITERATOR DEFINITIONS                                             */
    /* ---------------------------------------------------------------- */

    /*
    ** std::stack<T>::container_type is the type of the internal container
    ** (by default std::deque<T>). We take the iterators of this type and
    ** give them names matching standard containers (iterator /
    ** const_iterator), so MutatedStack can be used like a vector or list:
    **     MutatedStack<int>::iterator it = mstack.begin();
    **
    ** 'typename' is mandatory: container_type::iterator depends on T,
    ** so the compiler needs to know that this is a TYPE.
    */
    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;

    /* ---------------------------------------------------------------- */
    /*  NAVIGATION METHODS                                               */
    /* ---------------------------------------------------------------- */

    /*
    ** 'c' is the protected member of std::stack that stores the data.
    ** We use 'this->c' (and not just 'c') because the base class is dependent
    ** on the template: without 'this->' the compiler does not look up 'c' in the base
    ** and gives an "undeclared identifier" error.
    **
    ** begin() -> first element (the BOTTOM of the stack)
    ** end()   -> one position past the last (top + 1)
    */
    iterator begin() { return this->c.begin(); }
    iterator end() { return this->c.end(); }

    /*
    ** const versions: allow iterating over a constant MutatedStack
    ** (e.g., passed as 'const MutatedStack &'), returning
    ** const_iterator to prevent modifying the elements.
    */
    const_iterator begin() const { return this->c.begin(); }
    const_iterator end() const { return this->c.end(); }
};

#endif