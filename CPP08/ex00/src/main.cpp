#include <iostream>
#include <vector>
#include <list>
#include "../include/easyfind.hpp"

int main() {
    // 📦 1. Test with std::vector
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);

    try {
        // Success scenario: element exists
        std::vector<int>::iterator it = easyfind(vec, 20);
        std::cout << "✅ Found in vector: " << *it << std::endl;
    } catch (const std::exception &e) {
        std::cout << "❌ Error: " << e.what() << std::endl;
    }

    try {
        // Error scenario: element does not exist (should throw an exception)
        easyfind(vec, 99);
    } catch (const std::exception &e) {
        std::cout << "⚠️ Exception successfully caught: " << e.what() << std::endl;
    }

    // 🔗 2. Test with std::list
    std::list<int> lst;
    lst.push_back(100);
    lst.push_back(200);

    try {
        std::list<int>::iterator it = easyfind(lst, 100);
        std::cout << "✅ Found in list: " << *it << std::endl;
    } catch (const std::exception &e) {
        std::cout << "❌ Error: " << e.what() << std::endl;
    }

    return 0;
}