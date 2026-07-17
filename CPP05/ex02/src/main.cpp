#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include <iostream>

int main() {
    std::cout << "========== TEST 1: Creating Concrete Forms ==========" << std::endl;
    try {
        ShrubberyCreationForm shrub("garden");
        RobotomyRequestForm robot("Bender");
        PresidentialPardonForm pardon("Ford Prefect");
        
        std::cout << shrub << std::endl;
        std::cout << robot << std::endl;
        std::cout << pardon << std::endl;
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    std::cout << "\n========== TEST 2: Bureaucrats with Different Grades ==========" << std::endl;
    try {
        Bureaucrat high("High Rank", 1);      // Best bureaucrat
        Bureaucrat mid("Mid Rank", 75);       // Average
        Bureaucrat low("Low Rank", 150);      // Worst
        
        std::cout << high << std::endl;
        std::cout << mid << std::endl;
        std::cout << low << std::endl;
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    std::cout << "\n========== TEST 3: Signing and Executing Shrubbery Form ==========" << std::endl;
    try {
        Bureaucrat boss("Boss", 1);  // Can sign and execute anything
        ShrubberyCreationForm shrub("home");
        
        std::cout << "Before signing: " << shrub << std::endl;
        
        // Sign the form
        boss.signForm(shrub);
        std::cout << "After signing: " << shrub << std::endl;
        
        // Execute the form
        boss.executeForm(shrub);
        
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    std::cout << "\n========== TEST 4: Execute Form Without Signing ==========" << std::endl;
    try {
        Bureaucrat boss("Boss", 1);
        ShrubberyCreationForm shrub("park");
        
        // Try to execute without signing
        boss.executeForm(shrub);  // Should fail!
        
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    std::cout << "\n========== TEST 5: Grade Too Low for Execution ==========" << std::endl;
    try {
        Bureaucrat low("Low Rank", 150);
        ShrubberyCreationForm shrub("park");
        
        // Sign the form (shrubbery requires grade 145 to sign)
        low.signForm(shrub);  // Should fail! (150 > 145)
        
        // Even if we could sign it, execution requires grade 137
        // low grade 150 is too low for that too
        low.executeForm(shrub);  // Would fail anyway
        
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    std::cout << "\n========== TEST 6: Robotomy Request Form ==========" << std::endl;
    try {
        Bureaucrat high("Boss", 1);
        RobotomyRequestForm robot("Bender");
        
        high.signForm(robot);
        high.executeForm(robot);  // 50% chance of success
        high.executeForm(robot);  // 50% chance of success
        
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    std::cout << "\n========== TEST 7: Presidential Pardon Form ==========" << std::endl;
    try {
        Bureaucrat high("President", 1);
        PresidentialPardonForm pardon("Ford Prefect");
        
        high.signForm(pardon);
        high.executeForm(pardon);  // Should succeed!
        
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    std::cout << "\n========== TEST 8: Polymorphism with Base Class Pointer ==========" << std::endl;
    try {
        Bureaucrat boss("Boss", 1);
        AForm* forms[3];
        
        // Create different forms using base class pointer
        forms[0] = new ShrubberyCreationForm("garden");
        forms[1] = new RobotomyRequestForm("Bender");
        forms[2] = new PresidentialPardonForm("Arthur");
        
        // Sign and execute all forms polymorphically
        for (int i = 0; i < 3; i++) {
            boss.signForm(*forms[i]);
            boss.executeForm(*forms[i]);
            std::cout << std::endl;
        }
        
        // Clean up
        for (int i = 0; i < 3; i++) {
            delete forms[i];
        }
        
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    std::cout << "\n========== TEST 9: Copy and Assignment of Concrete Forms ==========" << std::endl;
    try {
        ShrubberyCreationForm original("original");
        Bureaucrat boss("Boss", 1);
        
        boss.signForm(original);
        
        // Copy constructor
        ShrubberyCreationForm copy(original);
        std::cout << "Original: " << original << std::endl;
        std::cout << "Copy: " << copy << std::endl;
        
        // Assignment
        ShrubberyCreationForm assigned("assigned");
        assigned = original;
        std::cout << "Assigned: " << assigned << std::endl;
        
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    std::cout << "\n========== All tests completed! ==========" << std::endl;
    return 0;
}