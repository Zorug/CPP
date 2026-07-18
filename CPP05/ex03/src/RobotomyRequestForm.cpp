#include "../include/RobotomyRequestForm.hpp"
#include <iostream>

// ===== CONSTRUCTORS =====
RobotomyRequestForm::RobotomyRequestForm() 
    : AForm("Robotomy Request", 72, 45), 
      _target("default") {
    // Initialize with default target
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) 
    : AForm("Robotomy Request", 72, 45), 
      _target(target) {
    // Initialize with given target
}

// ===== COPY CONSTRUCTOR =====
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) 
    : AForm(other), 
      _target(other._target) {
    // Copy AForm part and target
}

// ===== ASSIGNMENT OPERATOR =====
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        this->_target = other._target;
    }
    return *this;
}

// ===== DESTRUCTOR =====
RobotomyRequestForm::~RobotomyRequestForm() {
    // Nothing to clean up
}

// ===== GETTER =====
const std::string& RobotomyRequestForm::getTarget() const {
    return this->_target;
}

// ===== EXECUTE METHOD =====
void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
    // STEP 1: Check if form is signed
    if (!this->getIsSigned()) {
        throw AForm::FormNotSignedException();
    }
    
    // STEP 2: Check if executor's grade is high enough
    if (executor.getGrade() > this->getExecGrade()) {
        throw AForm::GradeTooLowException();
    }
    
    // STEP 3: Execute the action
    this->performRobotomy();
}

// ===== HELPER METHOD =====
void RobotomyRequestForm::performRobotomy() const {
    // Seed random number generator only once
    static bool seeded = false;
    if (!seeded) {
        std::srand(std::time(NULL));
        seeded = true;
    }
    
    // Make drilling noises
    std::cout << "* DRILLING NOISES * BZZZZZZZZZ * GRRRRR * BZZZZ *" << std::endl;
    std::cout << "* DRILLING NOISES * CLANK CLANK * WHIRRR *" << std::endl;
    
    // 50% chance of success
    int success = std::rand() % 2;  // Returns 0 or 1
    
    if (success) {
        std::cout << this->_target << " has been robotomized successfully!" << std::endl;
    } else {
        std::cout << "Robotomy of " << this->_target << " failed!" << std::endl;
    }
}