#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/Intern.hpp"
#include <iostream>

int main() {
    std::cout << "========== TEST 1: Creating Intern ==========" << std::endl;
    Intern intern;
    
    std::cout << "\n========== TEST 2: Intern creates valid forms ==========" << std::endl;
    try {
        // Intern creates different types of forms
        AForm* form1 = intern.makeForm("shrubbery creation", "Garden");
        AForm* form2 = intern.makeForm("robotomy request", "Bender");
        AForm* form3 = intern.makeForm("presidential pardon", "Zaphod");
        
        // Print the created forms
        std::cout << "\nCreated forms:" << std::endl;
        std::cout << *form1 << std::endl;
        std::cout << *form2 << std::endl;
        std::cout << *form3 << std::endl;
        
        // Clean up
        delete form1;
        delete form2;
        delete form3;
        
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    std::cout << "\n========== TEST 3: Intern creates unknown form ==========" << std::endl;
    try {
        Intern intern2;
        // This should fail - "unknown form" doesn't exist
        AForm* form = intern2.makeForm("unknown form", "Target");
        delete form;  // This line won't execute
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    std::cout << "\n========== TEST 4: Complete workflow with Intern ==========" << std::endl;
    try {
        // Create a bureaucrat and an intern
        Bureaucrat boss("Big Boss", 1);  // Can sign and execute everything
        Intern intern3;
        
        // Intern creates a form
        AForm* form = intern3.makeForm("robotomy request", "Marvin");
        
        std::cout << "\nBefore signing:" << std::endl;
        std::cout << *form << std::endl;
        
        // Bureaucrat signs and executes the form
        boss.signForm(*form);
        boss.executeForm(*form);
        
        // Clean up
        delete form;
        
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    std::cout << "\n========== TEST 5: Intern with different targets ==========" << std::endl;
    try {
        Intern intern4;
        
        // Create multiple forms with different targets
        AForm* forms[3];
        forms[0] = intern4.makeForm("shrubbery creation", "Backyard");
        forms[1] = intern4.makeForm("shrubbery creation", "Frontyard");
        forms[2] = intern4.makeForm("shrubbery creation", "Park");
        
        std::cout << "\nMultiple shrubbery forms:" << std::endl;
        for (int i = 0; i < 3; ++i) {
            std::cout << *forms[i] << std::endl;
            delete forms[i];
        }
        
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    std::cout << "\n========== TEST 6: Case sensitivity ==========" << std::endl;
    try {
        Intern intern5;
        
        // Try different capitalizations - should fail if not exact match
        std::cout << "Testing exact match: " << std::endl;
        AForm* form1 = intern5.makeForm("shrubbery creation", "Test");
        std::cout << *form1 << std::endl;
        delete form1;
        
        // These should fail (case sensitive)
        std::cout << "\nTesting wrong capitalization:" << std::endl;
        AForm* form2 = intern5.makeForm("Shrubbery Creation", "Test");
        delete form2;  // Won't execute
        
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    std::cout << "\n========== All tests completed! ==========" << std::endl;
    return 0;
}