#include "../include/PresidentialPardonForm.hpp"
#include <iostream>

// ===== CONSTRUCTORS =====
PresidentialPardonForm::PresidentialPardonForm() 
    : AForm("Presidential Pardon", 25, 5), 
      _target("default") {
    // Initialize with default target
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) 
    : AForm("Presidential Pardon", 25, 5), 
      _target(target) {
    // Initialize with given target
}

// ===== COPY CONSTRUCTOR =====
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) 
    : AForm(other), 
      _target(other._target) {
    // Copy AForm part and target
}

// ===== ASSIGNMENT OPERATOR =====
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        this->_target = other._target;
    }
    return *this;
}

// ===== DESTRUCTOR =====
PresidentialPardonForm::~PresidentialPardonForm() {
    // Nothing to clean up
}

// ===== GETTER =====
const std::string& PresidentialPardonForm::getTarget() const {
    return this->_target;
}

// ===== EXECUTE METHOD =====
void PresidentialPardonForm::execute(const Bureaucrat& executor) const {
    // STEP 1: Check if form is signed
    if (!this->getIsSigned()) {
        throw AForm::FormNotSignedException();
    }
    
    // STEP 2: Check if executor's grade is high enough
    if (executor.getGrade() > this->getExecGrade()) {
        throw AForm::GradeTooLowException();
    }
    
    // STEP 3: Execute the action
    this->grantPardon();
}

// ===== HELPER METHOD =====
void PresidentialPardonForm::grantPardon() const {
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
    std::cout << "All charges have been dropped. You are free!" << std::endl;
}