#include "../include/AForm.hpp"
#include "../include/Bureaucrat.hpp"

// ===== DEFAULT CONSTRUCTOR =====
AForm::AForm() 
    : _name("Default AForm"), 
      _isSigned(false), 
      _signGrade(150), 
      _execGrade(150) {
    // Default form with lowest grades
}

// ===== PARAMETERIZED CONSTRUCTOR =====
AForm::AForm(const std::string& name, int signGrade, int execGrade) 
    : _name(name),
      _isSigned(false),
      _signGrade(signGrade),
      _execGrade(execGrade) {
    
    // Validate both grades
    if (signGrade < 1 || execGrade < 1) {
        throw AForm::GradeTooHighException();
    }
    if (signGrade > 150 || execGrade > 150) {
        throw AForm::GradeTooLowException();
    }
}

// ===== COPY CONSTRUCTOR =====
AForm::AForm(const AForm& other) 
    : _name(other._name),
      _isSigned(other._isSigned),
      _signGrade(other._signGrade),
      _execGrade(other._execGrade) {
    // All attributes copied (including const ones)
}

// ===== ASSIGNMENT OPERATOR =====
AForm& AForm::operator=(const AForm& other) {
    if (this != &other) {
        // Only copy non-const member
        this->_isSigned = other._isSigned;
    }
    return *this;
}

// ===== DESTRUCTOR =====
AForm::~AForm() {
    // Virtual destructor - does nothing special
}

// ===== GETTERS =====
const std::string& AForm::getName() const {
    return this->_name;
}

bool AForm::getIsSigned() const {
    return this->_isSigned;
}

int AForm::getSignGrade() const {
    return this->_signGrade;
}

int AForm::getExecGrade() const {
    return this->_execGrade;
}

// ===== beSigned METHOD =====
void AForm::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > _signGrade) {
        throw AForm::GradeTooLowException();
    }
    this->_isSigned = true;
}

// ===== EXCEPTION CLASSES =====
const char* AForm::GradeTooHighException::what() const throw() {
    return "AForm grade is too high! Maximum grade is 1.";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "AForm grade is too low! Minimum grade is 150.";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "Form is not signed! Cannot execute.";
}

// ===== INSERTION OPERATOR =====
std::ostream& operator<<(std::ostream& os, const AForm& f) {
    os << "AForm: " << f.getName() 
       << ", sign grade: " << f.getSignGrade()
       << ", exec grade: " << f.getExecGrade()
       << ", signed: " << (f.getIsSigned() ? "yes" : "no");
    return os;
}