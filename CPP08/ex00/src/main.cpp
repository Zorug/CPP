/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 19:23:34 by cgross-s          #+#    #+#             */
/*   Updated: 2026/11/05 19:23:39 by cgross-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*  ex00 - main.cpp                                                           */
/*                                                                            */
/*  Tests for the easyfind template function. We cover 3 scenarios:           */
/*    1. Success in a std::vector (element exists)                            */
/*    2. Failure in a std::vector (element does not exist -> exception)       */
/*    3. Success in a std::list   (proves the template is generic)            */
/* ************************************************************************** */

#include <iostream>     // std::cout, std::endl
#include <vector>       // std::vector (container with contiguous memory)
#include <list>         // std::list   (doubly linked list)
#include "../include/easyfind.hpp"

int main() {
    // 📦 1. Test with std::vector
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);

    try {
        // Success scenario: element exists
        std::vector<int>::iterator it = easyfind(vec, 20);
        std::cout << "✅ Found in vector: " << *it << std::endl;
    } catch (const std::exception &e) {
        std::cout << "❌ Error: " << e.what() << std::endl;
    }

    try {
        // Error scenario: element does not exist (should throw an exception)
        easyfind(vec, 99);
    } catch (const std::exception &e) {
        std::cout << "⚠️ Exception successfully caught: " << e.what() << std::endl;
    }

    // 🔗 2. Test with std::list
    std::list<int> lst;
    lst.push_back(100);
    lst.push_back(200);

    try {
        std::list<int>::iterator it = easyfind(lst, 100);
        std::cout << "✅ Found in list: " << *it << std::endl;
    } catch (const std::exception &e) {
        std::cout << "❌ Error: " << e.what() << std::endl;
    }

    return 0;
}