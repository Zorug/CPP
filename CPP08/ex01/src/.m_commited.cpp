/*
** ex01 - Span Tests:
**   1. Capacity limit and exception when full
**   2. shortestSpan / longestSpan (subject example: should give 2 and 14)
**   3. Stress test: 10,000 numbers inserted via iterator range
*/

#include "../include/Span.hpp"
#include <iostream>
#include <vector>

int main() {

    /* ==================================================================== */
    /*  1. BASIC TEST + CAPACITY EXCEPTION                                  */
    /* ==================================================================== */
    try {
        Span sp(3);          /* maximum capacity: 3 numbers */
        sp.addNumber(10);    /* 1/3 */
        sp.addNumber(3);     /* 2/3 */
        sp.addNumber(20);    /* 3/3 -> full */
        sp.addNumber(40);    /* 4th number: DOES NOT fit -> throws out_of_range */

        /* If it reaches here, the exception was not thrown (failure). */
    } catch (const std::exception &e) {
        /* EXPECTED result: proves that the limit is respected. */
        std::cout << "✅ Exception caught: " << e.what() << std::endl;
    }

    /* ==================================================================== */
    /*  2. SHORTEST / LONGEST SPAN (subject example)                        */
    /* ==================================================================== */
    Span sp2(5);
    sp2.addNumber(6);
    sp2.addNumber(3);
    sp2.addNumber(17);
    sp2.addNumber(9);
    sp2.addNumber(11);

    /*
    ** Sorted: 3, 6, 9, 11, 17
    **   shortest = smallest difference between neighbors = 11 - 9 = 2
    **   longest  = 17 - 3 = 14
    **
    ** These calls are outside a try block because we know there are 5 numbers
    ** (>= 2), so they won't throw an exception.
    */
    std::cout << "📉 Shortest span: " << sp2.shortestSpan() << std::endl;
    std::cout << "📈 Longest span: " << sp2.longestSpan() << std::endl;

    /* ==================================================================== */
    /*  3. STRESS TEST WITH ITERATORS (10,000 ELEMENTS)                     */
    /* ==================================================================== */
    try {
        Span bigSpan(10000);

        /* Prepare the data in a vector: 0, 2, 4, ..., 19998. */
        std::vector<int> numbers;
        for (int i = 0; i < 10000; ++i) {
            numbers.push_back(i * 2);
        }

        /*
        ** Insert ALL of them at once with the template version of addNumber
        ** (range [begin, end)), instead of 10,000 individual addNumber calls.
        */
        bigSpan.addNumber(numbers.begin(), numbers.end());

        /*
        ** Expected results:
        **   shortest = 2       (all neighbors are spaced by 2)
        **   longest  = 19998   (19998 - 0)
        */
        std::cout << "🚀 BigSpan - Shortest: " << bigSpan.shortestSpan() << std::endl;
        std::cout << "🚀 BigSpan - Longest: " << bigSpan.longestSpan() << std::endl;
    } catch (const std::exception &e) {
        /* Unexpected errors go to stderr (cerr), by convention. */
        std::cerr << "❌ Error: " << e.what() << std::endl;
    }

    return 0;
}