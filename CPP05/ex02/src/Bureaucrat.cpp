#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp" // // Changed from Form.hpp

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

// ===== SIGN FORM =====
void Bureaucrat::signForm(AForm& form) {  // Changed from Form
    try {
        form.beSigned(*this);
        std::cout << _name << " signed " << form.getName() << std::endl;
    } catch (const std::exception& e) {
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

// ===== NEW: EXECUTE FORM =====
void Bureaucrat::executeForm(const AForm& form) {
    // This method attempts to execute a form
    // It calls AForm::execute() and handles exceptions
    
    try {
        // Try to execute the form
        // This will check if form is signed and if grade is sufficient
        // Note: execute() is a const method, so we can call it on const form
        form.execute(*this);
        
        // If successful, print success message
        // Format: <bureaucrat> executed <form>
        std::cout << _name << " executed " << form.getName() << std::endl;
        
    } catch (const std::exception& e) {
        // If execution failed, print error message
        std::cout << _name << " couldn't execute " << form.getName() 
                  << " because " << e.what() << std::endl;
    }
}