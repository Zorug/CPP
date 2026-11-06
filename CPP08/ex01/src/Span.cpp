/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 14:18:40 by cgross-s          #+#    #+#             */
/*   Updated: 2026/11/06 14:20:18 by cgross-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Span.hpp"
#include <algorithm>
#include <stdexcept>

Span::Span(unsigned int N) : _maxSize(N) {}

Span::Span(const Span &other) : _maxSize(other._maxSize), _numbers(other._numbers) {}

Span &Span::operator=(const Span &other) {
    if (this != &other) {
        _maxSize = other._maxSize;
        _numbers = other._numbers;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int number) {
    if (_numbers.size() >= _maxSize) {
        throw std::out_of_range("Span is full ⚠️");
    }
    _numbers.push_back(number);
}

int Span::shortestSpan() const {
    if (_numbers.size() < 2) {
        throw std::runtime_error("Not enough numbers to find a span 📉");
    }
    std::vector<int> tmp = _numbers;
    std::sort(tmp.begin(), tmp.end());
    
    int minSpan = tmp[1] - tmp[0];
    for (size_t i = 1; i < tmp.size() - 1; ++i) {
        int diff = tmp[i + 1] - tmp[i];
        if (diff < minSpan) {
            minSpan = diff;
        }
    }
    return minSpan;
}

int Span::longestSpan() const {
    if (_numbers.size() < 2) {
        throw std::runtime_error("Not enough numbers to find a span 📈");
    }
    std::vector<int> tmp = _numbers;
    std::sort(tmp.begin(), tmp.end());
    return tmp.back() - tmp.front();
}