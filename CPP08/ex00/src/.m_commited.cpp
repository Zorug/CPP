/* ************************************************************************** */
/*  ex00 - main.cpp                                                           */
/*                                                                            */
/*  Tests for the easyfind template function. We cover 3 scenarios:           */
/*    1. Success in a std::vector (element exists)                            */
/*    2. Failure in a std::vector (element does not exist -> exception)       */
/*    3. Success in a std::list   (proves the template is generic)            */
/* ************************************************************************** */

#include <iostream>   // std::cout, std::endl
#include <vector>     // std::vector (container with contiguous memory)
#include <list>       // std::list   (doubly linked list)
#include "easyfind.hpp"

int main() {

    /* ====================================================================== */
    /*  1. TEST WITH std::vector                                              */
    /* ====================================================================== */

    // In C++98, initialization with {10, 20, 30} does not exist, so
    // we populate the vector using push_back (appends to the end).
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);

    // --- SUCCESS scenario: the value 20 exists --------------------------
    // The try block "watches" the code: if easyfind throws an exception, the flow
    // jumps immediately to the corresponding catch block.
    try {
        // Since T = std::vector<int>, the return type is std::vector<int>::iterator.
        // (In C++98 there is no 'auto', we must write the type explicitly.)
        std::vector<int>::iterator it = easyfind(vec, 20);

        // *it = "dereference" the iterator = get the value it points to.
        std::cout << "✅ Found in vector: " << *it << std::endl;
    }
    // Catch std::exception by const reference, the base class of
    // all standard library exceptions (includes runtime_error).
    // By reference: avoids copying and avoids "slicing" (losing the derived type),
    // and e.what() calls the correct version of the message.
    catch (const std::exception &e) {
        std::cout << "❌ Error: " << e.what() << std::endl;
    }

    // --- ERROR scenario: the value 99 does NOT exist ---------------------
    // Here, what we want to test is precisely that the exception is thrown.
    try {
        // We don't store the return value because we don't expect it to return.
        // std::find returns end() -> easyfind throws runtime_error.
        easyfind(vec, 99);

        // If we reached this point, something would be wrong (the exception wasn't thrown).
        std::cout << "❌ Should have thrown an exception!" << std::endl;
    } catch (const std::exception &e) {
        // This is the EXPECTED result in this test.
        std::cout << "⚠️ Exception successfully caught: " << e.what() << std::endl;
    }

    /* ====================================================================== */
    /*  2. TEST WITH std::list                                                */
    /* ====================================================================== */

    // Same easyfind code, different container. This demonstrates the power
    // of templates + iterators: the algorithm doesn't know (nor need to know)
    // how the container stores data, it only needs begin() and end().
    std::list<int> lst;
    lst.push_back(100);
    lst.push_back(200);

    try {
        // Now T = std::list<int>, so the iterator is std::list<int>::iterator.
        std::list<int>::iterator it = easyfind(lst, 100);
        std::cout << "✅ Found in list: " << *it << std::endl;
    } catch (const std::exception &e) {
        std::cout << "❌ Error: " << e.what() << std::endl;
    }

    // Convention: 0 = program finished without errors.
    return 0;
}