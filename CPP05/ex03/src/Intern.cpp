#include "../include/Intern.hpp"
#include <iostream>

// ===== DEFAULT CONSTRUCTOR =====
Intern::Intern() {
    // Default constructor
    // Intern has no attributes, so nothing to initialize
    std::cout << "Intern created" << std::endl;
}

// ===== COPY CONSTRUCTOR =====
Intern::Intern(const Intern& other) {
    // Copy constructor
    // Intern has no attributes, so nothing to copy
    (void)other;  // Cast to void to avoid unused parameter warning
    std::cout << "Intern copied" << std::endl;
}

// ===== ASSIGNMENT OPERATOR =====
Intern& Intern::operator=(const Intern& other) {
    // Assignment operator
    // Intern has no attributes, so nothing to assign
    (void)other;  // Cast to void to avoid unused parameter warning
    std::cout << "Intern assigned" << std::endl;
    return *this;
}

// ===== DESTRUCTOR =====
Intern::~Intern() {
    // Destructor
    // Intern has no attributes, so nothing to clean up
    std::cout << "Intern destroyed" << std::endl;
}

// ===== PRIVATE STATIC CREATION METHODS =====
AForm* Intern::createShrubbery(const std::string& target) {
    // Creates a ShrubberyCreationForm
    // Static method: doesn't need an Intern instance
    std::cout << "Intern creates " << target << " shrubbery" << std::endl;
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomy(const std::string& target) {
    // Creates a RobotomyRequestForm
    // Static method: doesn't need an Intern instance
    std::cout << "Intern creates " << target << " robotomy request" << std::endl;
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidential(const std::string& target) {
    // Creates a PresidentialPardonForm
    // Static method: doesn't need an Intern instance
    std::cout << "Intern creates " << target << " presidential pardon" << std::endl;
    return new PresidentialPardonForm(target);
}

// ===== MAKE FORM METHOD =====
AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
    // This is the main method that creates forms
    // Uses a lookup table to avoid if/else chain
    
    // Define a structure to map form names to creation functions
    typedef struct {
        std::string name;                          // Form name to match
        AForm* (*creator)(const std::string&);    // Function pointer to creator
    } FormEntry;
    
    // Lookup table: array of form names and corresponding creator functions
    // This is the elegant solution - no if/else chain!
    FormEntry formEntries[] = {
        {"shrubbery creation", &Intern::createShrubbery},
        {"robotomy request", &Intern::createRobotomy},
        {"presidential pardon", &Intern::createPresidential}
    };
    
    // Calculate number of entries in the array
    const int numForms = sizeof(formEntries) / sizeof(formEntries[0]);
    
    // Search for the form name in the lookup table
    for (int i = 0; i < numForms; ++i) {
        if (formEntries[i].name == formName) {
            // Found the form! Call the creator function
            return formEntries[i].creator(target);
        }
    }
    
    // Form name not found - throw exception
    throw Intern::UnknownFormException();
}

// ===== EXCEPTION CLASS =====
const char* Intern::UnknownFormException::what() const throw() {
    // Returns error message for unknown form
    return "Error: Unknown form type requested!";
}