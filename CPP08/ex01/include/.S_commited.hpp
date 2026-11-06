/*
** ex01 - Span
**
** Class that stores a maximum of N integers and can calculate the shortest
** and longest distance (span) between any two stored numbers.
*/

/* INCLUDE GUARDS: prevent multiple inclusion of this header. */
#ifndef SPAN_HPP
#define SPAN_HPP

/*
** DEPENDENCIES (the header must be self-sufficient):
**  - <vector>    : std::vector, the container where we store the numbers.
**  - <algorithm> : STL algorithms (used in .cpp and consistency here).
**  - <iterator>  : std::distance, used in the template below.
**  - <stdexcept> : std::out_of_range, exception thrown when the Span is full.
*/
#include <vector>
#include <algorithm>
#include <iterator>
#include <stdexcept>

class Span {
private:
    /*
    ** _maxSize : maximum capacity (N), defined in the constructor and fixed.
    ** _numbers : the actual numbers stored.
    **
    ** Why std::vector? It grows dynamically (push_back/insert), accepts
    ** range-based insertion via iterators, and manages its own memory,
    ** so we don't need new/delete and there are no leaks.
    ** The limit N is enforced by us, not by the vector.
    */
    unsigned int _maxSize;
    std::vector<int> _numbers;

public:
    /* ---------------------------------------------------------------- */
    /*  ORTHODOX CANONICAL FORM (mandatory from module 02 to 09)        */
    /*  1. Constructor (here, parameterized: receives N)                 */
    /*  2. Copy constructor                                              */
    /*  3. Assignment operator                                           */
    /*  4. Destructor                                                    */
    /* ---------------------------------------------------------------- */
    Span(unsigned int N);
    Span(const Span &other);
    Span &operator=(const Span &other);
    ~Span();

    /* ---------------------------------------------------------------- */
    /*  CORE METHODS                                                    */
    /* ---------------------------------------------------------------- */

    /* Adds ONE number. Throws an exception if the Span is already full. */
    void addNumber(int number);

    /*
    ** Adds SEVERAL numbers at once, from a range of iterators [begin, end).
    ** This is the "bonus" requested by the subject.
    **
    ** Why is it a template?
    **   The range can come from a vector, list, deque, normal array...
    **   By receiving a generic 'Iterator', we accept all of them.
    **
    ** Why is it implemented in the header?
    **   Templates must be visible at the moment they are instantiated.
    **   This is the exception to the "no implementations in headers" rule.
    **
    ** It's an OVERLOAD of addNumber(int): when you call addNumber(10) the
    ** compiler chooses the regular version (1 argument); with 2 arguments
    ** it chooses this one.
    */
    template <typename Iterator>
    void addNumber(Iterator begin, Iterator end) {
        /*
        ** We check BEFORE inserting if everything will fit:
        **   (how many I already have) + (how many I will add) > capacity ?
        **
        ** std::distance(begin, end) returns how many elements are in the
        ** range (signed type), hence static_cast<size_t> to compare it
        ** with size() without sign warnings (-Wextra -Werror).
        **
        ** Validating first ensures the "strong exception guarantee": if it
        ** doesn't fit, the Span remains intact (we don't insert half the numbers).
        */
        if (_numbers.size() + static_cast<size_t>(std::distance(begin, end)) > _maxSize) {
            throw std::out_of_range("Span is full ⚠️");
        }
        /*
        ** vector::insert(position, first, last) copies the entire range to
        ** the end of the vector in a single call (more efficient than
        ** thousands of individual addNumber calls).
        */
        _numbers.insert(_numbers.end(), begin, end);
    }

    /* ---------------------------------------------------------------- */
    /*  SPAN CALCULATIONS                                               */
    /*  'const' at the end: these functions do not modify the object.   */
    /* ---------------------------------------------------------------- */
    int shortestSpan() const;   /* shortest difference between two numbers */
    int longestSpan() const;    /* longest difference (max - min)          */
};

#endif