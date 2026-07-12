#include "../include/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {
    // Default constructor
    // Creates a bureaucrat with default name and lowest possible grade
    // Grade 150 is the lowest (worst) grade
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name) {
    // Parameterized constructor
    // Creates a bureaucrat with given name and grade
    // Throws exception if grade is out of valid range (1-150)
    
    if (grade < 1) {
        throw Bureaucrat::GradeTooHighException();
        // Grade 0 or negative is too high (better than 1)
        // Remember: 1 is highest, 150 is lowest
    }
    if (grade > 150) {
        throw Bureaucrat::GradeTooLowException();
        // Grade 151+ is too low (worse than 150)
    }
    _grade = grade;
    // Only set grade if validation passes
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name),
    _grade(other._grade) {
    // Copy constructor
    // Creates a new bureaucrat as a copy of an existing one
    // _name is const, so we must use initialization list
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    // Assignment operator
    // Copies the grade from another bureaucrat
    // Name is const, so we CANNOT copy it (it remains unchanged)
    
    if (this != &other) {  // Check for self-assignment
        this->_grade = other._grade;
        // _name cannot be changed because it's const
        // This is intentional - names are unique and permanent
    }
    return *this;  // Return reference to current object
}

Bureaucrat::~Bureaucrat() {
    // Destructor
    // Called when object is destroyed
    // No dynamic memory allocation, so nothing special to clean up
}

const std::string& Bureaucrat::getName() const {
    // Getter for name
    // Returns const reference to avoid copying
    // const method: doesn't modify the object
    return this->_name;
}

int Bureaucrat::getGrade() const {
    // Getter for grade
    // Returns copy of grade (int is small, copy is cheap)
    // const method: doesn't modify the object
    return this->_grade;
}

void Bureaucrat::incrementGrade() {
    // Increments grade (makes it better)
    // Example: grade 3 becomes 2
    // Throws exception if result would be above highest grade (1)
    
    if (this->_grade - 1 < 1) {  // Would go above grade 1?
        throw Bureaucrat::GradeTooHighException();
        // Can't go higher than grade 1
    }
    this->_grade--;
    // Decrement the number to increase the grade
    // Because lower number = better grade
}

void Bureaucrat::decrementGrade() {
    // Decrements grade (makes it worse)
    // Example: grade 3 becomes 4
    // Throws exception if result would be below lowest grade (150)
    
    if (this->_grade + 1 > 150) {  // Would go below grade 150?
        throw Bureaucrat::GradeTooLowException();
        // Can't go lower than grade 150
    }
    this->_grade++;
    // Increment the number to decrease the grade
    // Because higher number = worse grade
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    // Returns error message for GradeTooHighException
    // throw() means this function guarantees not to throw exceptions
    return "Grade is too high! Maximum grade is 1.";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    // Returns error message for GradeTooLowException
    // throw() means this function guarantees not to throw exceptions
    return "Grade is too low! Minimum grade is 150.";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    // Overload of insertion operator for Bureaucrat
    // Allows printing: std::cout << bureaucrat;
    // Format: "<name>, bureaucrat grade <grade>"

    os << b.getName() << ", bureaucrat grade " << b.getGrade();
    return os;  // Return stream to allow chaining: cout << a << b;
}
