/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 14:46:26 by cgross-s          #+#    #+#             */
/*   Updated: 2026/11/06 14:46:40 by cgross-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Span.hpp"
#include <iostream>
#include <vector>

int main() {
    // 1. Basic test and exceptions
    try {
        Span sp(3);
        sp.addNumber(10);
        sp.addNumber(3);
        sp.addNumber(20);
        sp.addNumber(40); // Will exceed limit and throw exception
    } catch (const std::exception &e) {
        std::cout << "✅ Exception caught: " << e.what() << std::endl;
    }

    // 2. Shortest and longest span tests
    Span sp2(5);
    sp2.addNumber(6);
    sp2.addNumber(3);
    sp2.addNumber(17);
    sp2.addNumber(9);
    sp2.addNumber(11);

    std::cout << "📉 Shortest span: " << sp2.shortestSpan() << std::endl;
    std::cout << "📈 Longest span: " << sp2.longestSpan() << std::endl;

    // 3. Stress test with iterators (10,000 elements)
    try {
        Span bigSpan(10000);
        std::vector<int> numbers;
        for (int i = 0; i < 10000; ++i) {
            numbers.push_back(i * 2);
        }
        bigSpan.addNumber(numbers.begin(), numbers.end());
        std::cout << "🚀 BigSpan - Shortest: " << bigSpan.shortestSpan() << std::endl;
        std::cout << "🚀 BigSpan - Longest: " << bigSpan.longestSpan() << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "❌ Error: " << e.what() << std::endl;
    }

    return 0;
}