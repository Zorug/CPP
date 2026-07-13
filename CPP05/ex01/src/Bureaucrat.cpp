#include "../include/Bureaucrat.hpp"
#include "../include/Form.hpp"  // NEW

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name) {
    if (grade < 1) {
        throw Bureaucrat::GradeTooHighException();
    }
    if (grade > 150) {
        throw Bureaucrat::GradeTooLowException();
    }
    _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name),
    _grade(other._grade) {
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this != &other) {
        this->_grade = other._grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat() {
}

const std::string& Bureaucrat::getName() const {
    return this->_name;
}

int Bureaucrat::getGrade() const {
    return this->_grade;
}

void Bureaucrat::incrementGrade() {
    if (this->_grade - 1 < 1) {
        throw Bureaucrat::GradeTooHighException();
    }
    this->_grade--;
}

void Bureaucrat::decrementGrade() {
    if (this->_grade + 1 > 150) {
        throw Bureaucrat::GradeTooLowException();
    }
    this->_grade++;
}

// NEW METHOD IMPLEMENTATION
void Bureaucrat::signForm(Form& form) {
    // This method attempts to sign a form
    // It calls Form::beSigned() and handles any exceptions
    
    try {
        // Try to sign the form
        // This will throw Form::GradeTooLowException if grade is insufficient
        form.beSigned(*this);  // Pass the current bureaucrat (this)
        
        // If we reach here, signing was successful
        // Format: <bureaucrat> signed <form>
        std::cout << _name << " signed " << form.getName() << std::endl;
        
    } catch (const std::exception& e) {
        // If signing failed, catch the exception
        // Format: <bureaucrat> couldn't sign <form> because <reason>
        std::cout << _name << " couldn't sign " << form.getName() 
                  << " because " << e.what() << std::endl;
    }
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high! Maximum grade is 1.";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low! Minimum grade is 150.";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getName() << ", bureaucrat grade " << b.getGrade();
    return os;
}
