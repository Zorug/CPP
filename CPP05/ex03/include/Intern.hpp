#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
private:
    // Private helper method to create each form type
    // These are static because they don't need instance data
    static AForm* createShrubbery(const std::string& target);
    static AForm* createRobotomy(const std::string& target);
    static AForm* createPresidential(const std::string& target);

public:
    // Orthodox Canonical Form
    Intern();                               // Default constructor
    Intern(const Intern& other);            // Copy constructor
    Intern& operator=(const Intern& other); // Assignment operator
    ~Intern();                              // Destructor

    // Main method: creates a form based on form name
    // Returns a pointer to AForm (polymorphic)
    // Throws exception if form name doesn't exist
    AForm* makeForm(const std::string& formName, const std::string& target);

    // Custom exception for unknown form
    class UnknownFormException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
};

#endif