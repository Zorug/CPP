#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

// Forward declaration to avoid circular dependency
// We tell the compiler: "Form is a class that will be defined later"
class Form;

class Bureaucrat {
private:
    const std::string _name;
    int _grade;

public:
    // Orthodox Canonical Form
    Bureaucrat();
    Bureaucrat(const std::string& name, int grade);
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();

    // Getters - these are const because they don't modify the object
    const std::string& getName() const;
    int getGrade() const;

    // Grade modifiers - these can throw exceptions
    void incrementGrade();
    void decrementGrade();

    // NEW METHOD: Bureaucrat tries to sign a form
    // Takes a reference to a Form (non-const because we need to modify it)
    void signForm(Form& form);

    // Exception classes (same as ex00)
    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
};

// Overload of insertion operator (same as ex00)
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif