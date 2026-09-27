#include <iostream>
#include <string>
#include "../include/Array.hpp"

int main(void) {
    std::cout << "=== Test 1: Empty Array ===" << std::endl;
    Array<int> emptyArray;
    std::cout << "Empty array size: " << emptyArray.size() << std::endl;

    std::cout << "\n=== Test 2: Array of integers ===" << std::endl;
    Array<int> intArray(5);
    std::cout << "Int array size: " << intArray.size() << std::endl;
    std::cout << "Default initialized values: ";
    for (unsigned int i = 0; i < intArray.size(); i++) {
        std::cout << intArray[i] << " ";
    }
    std::cout << std::endl;

    // Modifying elements
    for (unsigned int i = 0; i < intArray.size(); i++) {
        intArray[i] = (i + 1) * 10;
    }

    std::cout << "Modified values: ";
    for (unsigned int i = 0; i < intArray.size(); i++) {
        std::cout << intArray[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "\n=== Test 3: Deep Copy & Assignment ===" << std::endl;
    Array<int> copyArray(intArray);
    Array<int> assignedArray;
    assignedArray = intArray;

    // Modify the original array to prove copies are independent
    intArray[0] = 999;

    std::cout << "Original array after change: " << intArray[0] << std::endl;
    std::cout << "Copy array (should be unchanged): " << copyArray[0] << std::endl;
    std::cout << "Assigned array (should be unchanged): " << assignedArray[0] << std::endl;

    std::cout << "\n=== Test 4: Array of Strings ===" << std::endl;
    Array<std::string> stringArray(3);
    stringArray[0] = "Hello";
    stringArray[1] = "C++";
    stringArray[2] = "Templates";

    for (unsigned int i = 0; i < stringArray.size(); i++) {
        std::cout << "stringArray[" << i << "] = " << stringArray[i] << std::endl;
    }

    std::cout << "\n=== Test 5: Out of Bounds Exception ===" << std::endl;
    //try {
        std::cout << "Attempting to access index 5..." << std::endl;
        std::cout << intArray[5] << std::endl; // Should throw exception
    //} catch (const std::exception& e) {
        //std::cerr << "Exception caught: " << e.what() << std::endl;
    //}

    try {
        std::cout << "Attempting to access index -1..." << std::endl;
        // -1 converts to a very large unsigned int
        std::cout << intArray[-1] << std::endl; // Should throw exception
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}