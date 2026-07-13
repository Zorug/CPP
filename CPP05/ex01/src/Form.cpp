#include "../include/Form.hpp"

// ===== DEFAULT CONSTRUCTOR =====
Form::Form() 
    : _name("Default Form"), 
      _isSigned(false), 
      _signGrade(150), 
      _execGrade(150) {
    // Creates a default form with lowest possible grades
    // This ensures the form can be signed by any bureaucrat
    // But practically, you would never use this constructor
}

// ===== PARAMETERIZED CONSTRUCTOR =====
Form::Form(const std::string& name, int signGrade, int execGrade) 
    : _name(name),           // Initialize const name
      _isSigned(false),      // Forms start unsigned
      _signGrade(signGrade), // Initialize const sign grade
      _execGrade(execGrade) { // Initialize const exec grade
    
    // VALIDATE BOTH GRADES
    // Check if signGrade is too high (less than 1)
    if (signGrade < 1) {
        throw Form::GradeTooHighException();
        // Object is NOT created if exception is thrown
    }
    
    // Check if signGrade is too low (greater than 150)
    if (signGrade > 150) {
        throw Form::GradeTooLowException();
    }
    
    // Check if execGrade is too high (less than 1)
    if (execGrade < 1) {
        throw Form::GradeTooHighException();
    }
    
    // Check if execGrade is too low (greater than 150)
    if (execGrade > 150) {
        throw Form::GradeTooLowException();
    }
    
    // All validation passed! Object is fully constructed.
}

// ===== COPY CONSTRUCTOR =====
Form::Form(const Form& other) 
    : _name(other._name),           // Copy const name
      _isSigned(other._isSigned),   // Copy non-const bool
      _signGrade(other._signGrade), // Copy const sign grade
      _execGrade(other._execGrade) { // Copy const exec grade
    // All attributes can be copied in copy constructor
    // Because we're creating a NEW object, not modifying an existing one
    // This is the ONLY way to "copy" const members
}

// ===== ASSIGNMENT OPERATOR =====
Form& Form::operator=(const Form& other) {
    // IMPORTANT: We can ONLY copy non-const members!
    // Const members (_name, _signGrade, _execGrade) cannot be changed
    // This is by design - they are fixed for the lifetime of the object
    
    if (this != &other) {  // Check for self-assignment
        // Only copy the non-const member
        this->_isSigned = other._isSigned;
        // _name remains unchanged
        // _signGrade remains unchanged
        // _execGrade remains unchanged
    }
    return *this;  // Return reference to current object
}

// ===== DESTRUCTOR =====
Form::~Form() {
    // Nothing to clean up - no dynamic memory
}

// ===== GETTERS =====
const std::string& Form::getName() const {
    return this->_name;  // Return const reference to avoid copy
}

bool Form::getIsSigned() const {
    return this->_isSigned;  // Return by value (bool is tiny)
}

int Form::getSignGrade() const {
    return this->_signGrade;  // Return by value (int is tiny)
}

int Form::getExecGrade() const {
    return this->_execGrade;  // Return by value (int is tiny)
}

// ===== CORE METHOD: beSigned =====
void Form::beSigned(const Bureaucrat& bureaucrat) {
    // This method attempts to sign the form
    // It checks if the bureaucrat's grade is high enough
    
    // IMPORTANT: Grade comparison
    // Grade 1 is HIGHER (better) than grade 2
    // A bureaucrat with grade 5 can sign a form requiring grade 10
    // Because 5 < 10 (5 is better than 10)
    // So we check: bureaucrat.getGrade() <= _signGrade
    
    if (bureaucrat.getGrade() > _signGrade) {
        // Bureaucrat's grade is WORSE than required
        // Example: bureaucrat grade 50, form requires grade 10
        // 50 > 10, so bureaucrat is not good enough
        throw Form::GradeTooLowException();
        // The form remains unsigned
    }
    
    // Grade is sufficient! Sign the form
    this->_isSigned = true;
}

// ===== EXCEPTION CLASSES =====
const char* Form::GradeTooHighException::what() const throw() {
    return "Form grade is too high! Maximum grade is 1.";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Form grade is too low! Minimum grade is 150.";
}

// ===== INSERTION OPERATOR OVERLOAD =====
std::ostream& operator<<(std::ostream& os, const Form& f) {
    // Print all form information in required format
    os << "Form: " << f.getName() 
       << ", sign grade: " << f.getSignGrade()
       << ", exec grade: " << f.getExecGrade()
       << ", signed: " << (f.getIsSigned() ? "yes" : "no");
    return os;  // Return stream to allow chaining
}
