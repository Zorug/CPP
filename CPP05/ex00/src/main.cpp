#include "../include/Bureaucrat.hpp"
#include <iostream>

int main() {
    std::cout << "========== TEST 1: Creating valid bureaucrats ==========" << std::endl;
    try {
        Bureaucrat b1("John", 1);      // Highest grade
        Bureaucrat b2("Sarah", 150);   // Lowest grade
        Bureaucrat b3("Mike", 75);     // Middle grade
        
        std::cout << b1 << std::endl;
        std::cout << b2 << std::endl;
        std::cout << b3 << std::endl;
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }


    std::cout << "\n========== TEST 2: Creating invalid bureaucrats ==========" << std::endl;
    try {
        Bureaucrat b4("TooHigh", 0);    // Grade too high (> 1)
        std::cout << b4 << std::endl;   // This line won't execute
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    try {
        Bureaucrat b5("TooLow", 151);   // Grade too low (< 150)
        std::cout << b5 << std::endl;   // This line won't execute
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    

    std::cout << "\n========== TEST 3: Incrementing grades ==========" << std::endl;
    try {
        Bureaucrat b6("Alice", 3);
        std::cout << "Before increment: " << b6 << std::endl;
        
        b6.incrementGrade();  // 3 -> 2
        std::cout << "After increment: " << b6 << std::endl;
        
        b6.incrementGrade();  // 2 -> 1
        std::cout << "After another increment: " << b6 << std::endl;
        
        // This should fail (can't go above grade 1)
        b6.incrementGrade();  // 1 -> 0 (INVALID!)
        std::cout << b6 << std::endl;   // This line won't execute
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }


    std::cout << "\n========== TEST 4: Decrementing grades ==========" << std::endl;
    try {
        Bureaucrat b7("Bob", 148);
        std::cout << "Before decrement: " << b7 << std::endl;
        
        b7.decrementGrade();  // 148 -> 149
        std::cout << "After decrement: " << b7 << std::endl;
        
        b7.decrementGrade();  // 149 -> 150
        std::cout << "After another decrement: " << b7 << std::endl;
        
        // This should fail (can't go below grade 150)
        b7.decrementGrade();  // 150 -> 151 (INVALID!)
        std::cout << b7 << std::endl;   // This line won't execute
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }


    /*std::cout << "\n========== TEST 5: Copy constructor and assignment ==========" << std::endl;
    try {
        Bureaucrat b8("Original", 42);
        Bureaucrat b9(b8);  // Copy constructor
        Bureaucrat b10("Copy", 100);
        b10 = b8;           // Assignment operator
        
        std::cout << "Original: " << b8 << std::endl;
        std::cout << "Copy (via copy constructor): " << b9 << std::endl;
        std::cout << "Copy (via assignment): " << b10 << std::endl;
        
        // Note: names remain different because name is const
        std::cout << "\nName of b9: " << b9.getName() << " (copied from b8)" << std::endl;
        std::cout << "Name of b10: " << b10.getName() << " (original name preserved)" << std::endl;
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }*/


    std::cout << "\n========== TEST 6: Getters ==========" << std::endl;
    try {
        Bureaucrat b11("TestGetters", 99);
        
        std::cout << "Name: " << b11.getName() << std::endl;
        std::cout << "Grade: " << b11.getGrade() << std::endl;
        
        // These should work even on const objects
        const Bureaucrat b12("ConstGetters", 50);
        std::cout << "Const object name: " << b12.getName() << std::endl;
        std::cout << "Const object grade: " << b12.getGrade() << std::endl;
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    std::cout << "\n========== All tests completed! ==========" << std::endl;
    return 0;
}

