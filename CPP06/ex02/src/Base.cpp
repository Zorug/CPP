#include "Base.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <exception>

// Randomly instantiates A, B, or C and returns it as a Base pointer
Base* generate(void) {
    int randomChoice = std::rand() % 3;

    switch (randomChoice) {
        case 0:
            std::cout << "Generated: A" << std::endl;
            return new A();
        case 1:
            std::cout << "Generated: B" << std::endl;
            return new B();
        default:
            std::cout << "Generated: C" << std::endl;
            return new C();
    }
}

// Identifies the real type using a POINTER
// dynamic_cast returns NULL if the cast is not valid
void identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}

// Identifies the real type using a REFERENCE
// References cannot be NULL, so dynamic_cast throws an exception on failure
void identify(Base& p) {
    // Attempt to cast to reference A
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    } catch (const std::exception&) {}

    // Attempt to cast to reference B
    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    } catch (const std::exception&) {}

    // Attempt to cast to reference C
    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    } catch (const std::exception&) {}

    std::cout << "Unknown type" << std::endl;
}