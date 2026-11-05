/* ************************************************************************** */
/*  ex00 - easyfind.hpp                                                       */
/*                                                                            */
/*  Objective: Find the FIRST occurrence of an integer inside an              */
/*  integer container (vector, list, deque...).                               */
/* ************************************************************************** */

/*
** INCLUDE GUARDS
** Prevent "double inclusion": if this header is included twice in the same
** compilation unit, the preprocessor skips the content on the second pass.
** The subject requires this (no guards = grade 0).
*/
#ifndef EASYFIND_HPP
#define EASYFIND_HPP

/*
** DEPENDENCIES
** Each header must include everything it needs (subject rule),
** so it can be used alone, without depending on the inclusion order of the main.
**
**  - <algorithm> : provides std::find (the STL algorithm we will use).
**  - <stdexcept> : provides std::runtime_error (the exception we will throw).
**
** Note: this module REQUIRES using STL algorithms whenever
** appropriate. That's why we use std::find instead of writing a manual for-loop.
*/
#include <algorithm>
#include <stdexcept>

/*
** FUNCTION TEMPLATE
**
** template <typename T>
**   -> T is a "generic type". The compiler replaces T with the actual type
**      of the container at the call site. E.g.: easyfind(vec, 20) with
**      vec of type std::vector<int>  =>  T = std::vector<int>.
**
** typename T::iterator
**   -> Return type: the iterator of container T.
**   -> The word 'typename' is mandatory because T::iterator is a "dependent
**      name" (it depends on T, which is not yet known). Without 'typename'
**      the compiler doesn't know if T::iterator is a type or a value.
**
** (T &container, int value)
**   -> container: passed by REFERENCE (no copying, and the returned iterator
**      points to the ORIGINAL container, not a copy that would die
**      at the end of the function).
**   -> value: the integer to search for (the subject specifies the 2nd parameter is an int).
**
** Since template functions can stay in the header (exception to the "no
** implementations in headers" rule), the full definition is here.
*/
template <typename T>
typename T::iterator easyfind(T &container, int value) {

    /*
    ** std::find(first, last, value)
    **   -> Traverses the range [first, last) and returns an iterator to the
    **      FIRST element equal to 'value'.
    **   -> If it doesn't find anything, it returns 'last' (in this case container.end()).
    **   -> Works with any sequential container, because it only needs
    **      iterators (vector, list, deque...).
    */
    typename T::iterator it = std::find(container.begin(), container.end(), value);

    /*
    ** "NOT FOUND" HANDLING
    ** end() does not point to a valid element: it's the position "one past the
    ** last". If 'it' equals end(), it means the value does not exist.
    ** The subject allows throwing an exception OR returning an error value.
    ** We chose the exception, which is the cleanest way to signal the error
    ** (and there is no universal "invalid" iterator value to return).
    */
    if (it == container.end()) {
        throw std::runtime_error("Element not found in container");
    }

    /*
    ** Found: we return the iterator. The caller can:
    **   - read the value       : *it
    **   - modify the value     : *it = 42;
    **   - calculate position   : std::distance(container.begin(), it)
    */
    return it;
}

#endif /* EASYFIND_HPP */