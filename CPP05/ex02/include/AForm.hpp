#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

// Forward declaration
class Bureaucrat;

class AForm {
private:
    // Same attributes as Form in ex01, but now they're protected? NO!
    // Subject says: "Keep in mind that the form's attributes 
    // need to remain private and that they belong to the base class."
    const std::string _name;
    bool _isSigned;
    const int _signGrade;
    const int _execGrade;

public:
    // Orthodox Canonical Form
    AForm();
    AForm(const std::string& name, int signGrade, int execGrade);
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);
    virtual ~AForm();  // Virtual destructor is important for polymorphism!

    // Getters - all const
    const std::string& getName() const;
    bool getIsSigned() const;
    int getSignGrade() const;
    int getExecGrade() const;

    // Core methods
    void beSigned(const Bureaucrat& bureaucrat);
    
    // NEW: Pure virtual function - makes AForm abstract!
    // This means: "Every derived class MUST implement this method"
    // The '= 0' makes it a pure virtual function
    // This is what makes AForm an abstract class
    virtual void execute(const Bureaucrat& executor) const = 0;

    // Nested exception classes
    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    // NEW: Exception for forms that are not signed
    class FormNotSignedException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
};

// Overload of insertion operator
std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif