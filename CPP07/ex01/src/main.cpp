#include <iostream>
#include <string>
#include "iter.hpp"

// Function template to print an element (const reference)
template <typename T>
void printElement(const T &element) {
    std::cout << element << " ";
}

// Function to increment an integer element (non-const reference)
void incrementInt(int &n) {
    n++;
}

// Function to convert a string element to uppercase (non-const reference)
void toUpperString(std::string &s) {
    for (size_t i = 0; i < s.length(); i++) {
        s[i] = std::toupper(s[i]);
    }
}

int main(void) {
    std::cout << "--- Test 1: Integer Array ---" << std::endl;
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intLen = 5;

    std::cout << "Original array: ";
    ::iter(intArray, intLen, printElement<int>);
    std::cout << std::endl;

    std::cout << "Incrementing elements..." << std::endl;
    ::iter(intArray, intLen, incrementInt);

    std::cout << "Modified array: ";
    ::iter(intArray, intLen, printElement<int>);
    std::cout << std::endl << std::endl;

    std::cout << "--- Test 2: Const String Array ---" << std::endl;
    const std::string strArray[] = {"apple", "banana", "cherry"};
    size_t strLen = 3;

    std::cout << "Const string array elements: ";
    ::iter(strArray, strLen, printElement<std::string>);
    std::cout << std::endl << std::endl;

    std::cout << "--- Test 3: Modifying String Array ---" << std::endl;
    std::string fruits[] = {"apple", "banana", "cherry"};

    std::cout << "Original fruits: ";
    ::iter(fruits, strLen, printElement<std::string>);
    std::cout << std::endl;

    std::cout << "Converting to uppercase..." << std::endl;
    ::iter(fruits, strLen, toUpperString);

    std::cout << "Modified fruits: ";
    ::iter(fruits, strLen, printElement<std::string>);
    std::cout << std::endl;

    return 0;
}