/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 14:46:45 by cgross-s          #+#    #+#             */
/*   Updated: 2026/11/06 15:40:33 by cgross-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>       // std::vector
#include <algorithm>    // STL algorithms
#include <iterator>     // std::distance
#include <stdexcept>    // std::out_of_range

class Span {
private:
    unsigned int _maxSize;
    std::vector<int> _numbers;

public:
    // 🏗️ Orthodox Canonical Form
    Span(unsigned int N);
    Span(const Span &other);
    Span &operator=(const Span &other);
    ~Span();

    // 📥 Core methods
    void addNumber(int number);

    template <typename Iterator>
    void addNumber(Iterator begin, Iterator end) {
        if (_numbers.size() + static_cast<size_t>(std::distance(begin, end)) > _maxSize) {
            throw std::out_of_range("Span is full ⚠️");
        }
        _numbers.insert(_numbers.end(), begin, end);
    }

    // 📊 Span calculations
    int shortestSpan() const;
    int longestSpan() const;
};

#endif