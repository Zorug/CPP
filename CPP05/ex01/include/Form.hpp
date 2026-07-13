#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"  // Include Bureaucrat because we use it in methods

class Form {
private:
    // All attributes are private as required by subject
    const std::string _name;      // Form name (constant)
    bool _isSigned;               // Signed status (false by default)
    const int _signGrade;         // Grade required to sign (constant)
    const int _execGrade;         // Grade required to execute (constant)

public:
    // Orthodox Canonical Form
    // Default constructor - creates a form with default values
    Form();
    
    // Parameterized constructor - creates a form with specific values
    // Uses initialization list for const members
    Form(const std::string& name, int signGrade, int execGrade);
    
    // Copy constructor - copies all attributes (including const ones)
    Form(const Form& other);
    
    // Assignment operator - only copies non-const members
    // Const members cannot be copied in assignment
    Form& operator=(const Form& other);
    
    // Destructor
    ~Form();

    // Getters - all are const because they don't modify the object
    const std::string& getName() const;
    bool getIsSigned() const;
    int getSignGrade() const;
    int getExecGrade() const;

    // Core method: tries to sign the form
    // Takes a const Bureaucrat reference (we only need to read its grade)
    // Throws GradeTooLowException if bureaucrat's grade is insufficient
    void beSigned(const Bureaucrat& bureaucrat);

    // Nested exception classes
    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
};

// Overload of insertion operator for Form
// Prints all form information in a readable format
std::ostream& operator<<(std::ostream& os, const Form& f);

#endif