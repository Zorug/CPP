/* ************************************************************************** */
/*  ex00 - easyfind.hpp                                                       */
/*                                                                            */
/*  Objective: Find the FIRST occurrence of an integer inside an              */
/*  integer container (vector, list, deque...).                               */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <stdexcept>

template <typename T>
typename T::iterator easyfind(T &container, int value) {
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    
    if (it == container.end()) {
        throw std::runtime_error("Elemento não encontrado no contentor");
    }
    
    return it;
}

#endif