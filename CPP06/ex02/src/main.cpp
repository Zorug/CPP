#include "Base.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main(void) {
    // Seed the random number generator
    std::srand(static_cast<unsigned int>(std::time(NULL)));

    std::cout << "=== Test 1: Random Generation & Identification ===" << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << "\n--- Iteration " << i + 1 << " ---" << std::endl;
        
        // Generate a random instance (A, B, or C)
        Base* instance = generate();

        // Identify using pointer
        std::cout << "Identify via pointer: ";
        identify(instance);

        // Identify using reference
        std::cout << "Identify via reference: ";
        identify(*instance);

        // Clean up memory to prevent leaks
        delete instance;
    }

    std::cout << "\n=== Test 2: NULL Pointer Test ===" << std::endl;
    Base* nullPtr = NULL;
    std::cout << "Identify NULL pointer: ";
    identify(nullPtr);

    return 0;
}