#include "../include/Span.hpp"
#include <algorithm>   /* std::sort */
#include <stdexcept>   /* std::out_of_range, std::runtime_error */

/* ======================================================================== */
/*  ORTHODOX CANONICAL FORM                                                 */
/* ======================================================================== */

/*
** Parameterized constructor.
** Uses the INITIALIZATION LIST (": _maxSize(N)") to set the capacity.
** _numbers does not appear in the list: it is default-constructed (empty vector).
** The body {} is empty because there is nothing else to do.
*/
Span::Span(unsigned int N) : _maxSize(N) {}

/*
** Copy constructor.
** Copies capacity and vector. std::vector already performs a DEEP COPY
** (duplicates the elements), so there is no memory sharing between
** objects and we don't need new/delete.
*/
Span::Span(const Span &other) : _maxSize(other._maxSize), _numbers(other._numbers) {}

/*
** Assignment operator.
** The "this != &other" check protects against self-assignment (sp = sp):
** it avoids useless work and is an important habit when dynamic
** resources are involved. Returns *this to allow chaining (a = b = c).
*/
Span &Span::operator=(const Span &other) {
    if (this != &other) {
        _maxSize = other._maxSize;
        _numbers = other._numbers;   /* vector::operator= copies everything */
    }
    return *this;
}

/* Destructor: nothing to free manually, the vector cleans itself up (RAII). */
Span::~Span() {}

/* ======================================================================== */
/*  METHODS                                                                 */
/* ======================================================================== */

/*
** addNumber: adds a single number.
** If we already have N (or more) elements, nothing else fits -> exception.
** The limit is enforced here because the vector on its own would grow infinitely.
*/
void Span::addNumber(int number) {
    if (_numbers.size() >= _maxSize) {
        throw std::out_of_range("Span is full ⚠️");
    }
    _numbers.push_back(number);
}

/*
** shortestSpan: smallest difference between any two numbers.
**
** KEY IDEA: after SORTING, the two numbers closest to each other
** are always ADJACENT. Thus, we just compare neighbors (O(n)) instead of
** comparing all pairs (O(n²)). With 10,000 numbers the difference is massive.
**
** Total complexity: O(n log n), dominated by sort.
*/
int Span::shortestSpan() const {
    /* With 0 or 1 numbers, no "distance" exists -> exception (subject requirement). */
    if (_numbers.size() < 2) {
        throw std::runtime_error("Not enough numbers to find a span 📉");
    }

    /*
    ** We work on a sorted COPY. The function is const, so it cannot
    ** modify _numbers; additionally, we don't want to change the user's
    ** original insertion order.
    */
    std::vector<int> tmp = _numbers;
    std::sort(tmp.begin(), tmp.end());

    /* Starting point: difference between the first two (already sorted). */
    int minSpan = tmp[1] - tmp[0];

    /*
    ** We iterate through the remaining adjacent pairs (i, i+1).
    ** i < tmp.size() - 1 ensures tmp[i + 1] never goes out of bounds.
    ** (size >= 2 was already guaranteed above, so "size() - 1" does not
    ** underflow on an unsigned type.)
    */
    for (size_t i = 1; i < tmp.size() - 1; ++i) {
        int diff = tmp[i + 1] - tmp[i];   /* >= 0 because it's sorted */
        if (diff < minSpan) {
            minSpan = diff;
        }
    }
    return minSpan;
}

/*
** longestSpan: largest difference between any two numbers.
** It is always (max value) - (min value). After sorting, the minimum is
** at the front and the maximum at the end.
**
** Note: std::min_element / std::max_element could also be used (O(n),
** without sorting), which would be even more efficient. Sorting works as well.
*/
int Span::longestSpan() const {
    if (_numbers.size() < 2) {
        throw std::runtime_error("Not enough numbers to find a span 📈");
    }
    std::vector<int> tmp = _numbers;
    std::sort(tmp.begin(), tmp.end());
    return tmp.back() - tmp.front();   /* last (max) - first (min) */
}