#include "../include/Bureaucrat.hpp"
#include "../include/Form.hpp"
#include <iostream>

int main() {
    std::cout << "========== TEST 1: Creating valid forms ==========" << std::endl;
    try {
        Form f1("Tax Form", 10, 5);
        Form f2("Secret Form", 1, 1);
        Form f3("Public Form", 150, 150);
        
        std::cout << f1 << std::endl;
        std::cout << f2 << std::endl;
        std::cout << f3 << std::endl;
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    std::cout << "\n========== TEST 2: Creating invalid forms ==========" << std::endl;
    try {
        Form f1("Too High", 0, 5);  // signGrade too high (> 1)
        std::cout << f1 << std::endl;
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    try {
        Form f2("Too Low", 10, 151);  // execGrade too low (< 150)
        std::cout << f2 << std::endl;
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    std::cout << "\n========== TEST 3: Successful signing ==========" << std::endl;
    try {
        Bureaucrat boss("Big Boss", 5);  // Grade 5 is very good
        Form taxForm("Tax Form", 10, 5);  // Needs grade 10 to sign
        
        std::cout << "Before signing:" << std::endl;
        std::cout << boss << std::endl;
        std::cout << taxForm << std::endl;
        
        boss.signForm(taxForm);  // Should succeed!
        
        std::cout << "\nAfter signing:" << std::endl;
        std::cout << taxForm << std::endl;
        
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    std::cout << "\n========== TEST 4: Failed signing (grade too low) ==========" << std::endl;
    try {
        Bureaucrat intern("Intern", 50);  // Grade 50 is mediocre
        Form secretForm("Secret Form", 10, 5);  // Needs grade 10 to sign
        
        std::cout << "Before signing:" << std::endl;
        std::cout << intern << std::endl;
        std::cout << secretForm << std::endl;
        
        intern.signForm(secretForm);  // Should fail!
        // Intern grade 50 < required grade 10 → FAIL
        
        std::cout << "\nAfter signing:" << std::endl;
        std::cout << secretForm << std::endl;  // Still unsigned
        
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    std::cout << "\n========== TEST 5: Form copy and assignment ==========" << std::endl;
    try {
        Form original("Original Form", 20, 10);
        original.beSigned(Bureaucrat("Boss", 15));  // Sign it
        
        std::cout << "Original: " << original << std::endl;
        
        // Copy constructor - copies everything
        Form copy(original);
        std::cout << "Copy (via copy constructor): " << copy << std::endl;
        
        // Assignment operator - copies only non-const members
        Form assigned("Assigned Form", 30, 20);
        assigned = original;
        std::cout << "Assigned (via assignment): " << assigned << std::endl;
        // Note: name, signGrade, execGrade remain from "Assigned Form"
        // Only _isSigned was copied (becomes true)
        
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    std::cout << "\n========== TEST 6: Multiple attempts to sign ==========" << std::endl;
    try {
        Form important("Important Form", 5, 1);
        Bureaucrat manager("Manager", 10);
        Bureaucrat ceo("CEO", 1);
        
        std::cout << "Initial state:" << std::endl;
        std::cout << important << std::endl;
        
        // Manager tries (grade 10 < required 5 → fails)
        manager.signForm(important);
        std::cout << "After manager attempt: " << important << std::endl;
        
        // CEO tries (grade 1 >= required 5 → succeeds)
        ceo.signForm(important);
        std::cout << "After CEO attempt: " << important << std::endl;
        
        // Try to sign again (already signed)
        manager.signForm(important);  // Will succeed (form already signed)
        std::cout << "After second attempt: " << important << std::endl;
        
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    std::cout << "\n========== All tests completed! ==========" << std::endl;
    return 0;
}