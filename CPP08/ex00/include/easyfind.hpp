/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 19:23:25 by cgross-s          #+#    #+#             */
/*   Updated: 2026/11/05 19:23:30 by cgross-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*  ex00 - easyfind.hpp                                                       */
/*                                                                            */
/*  Objective: Find the FIRST occurrence of an integer inside an              */
/*  integer container (vector, list, deque...).                               */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>    // std::find
#include <stdexcept>    // std::runtime_error

template <typename T>
typename T::iterator easyfind(T &container, int value) {
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    
    if (it == container.end()) {
        throw std::runtime_error("Elemento não encontrado no contentor");
    }
    
    return it;
}

#endif