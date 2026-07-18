#include "../include/ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

// ===== CONSTRUCTORS =====
ShrubberyCreationForm::ShrubberyCreationForm() 
    : AForm("Shrubbery Creation", 145, 137), 
      _target("default") {
    // Calls AForm constructor with required grades
    // Uses the "default" target
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) 
    : AForm("Shrubbery Creation", 145, 137), 
      _target(target) {
    // Initialize target with given value
}

// ===== COPY CONSTRUCTOR =====
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) 
    : AForm(other),  // Copy AForm part
      _target(other._target) {
    // Copy target
}

// ===== ASSIGNMENT OPERATOR =====
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other) {
        // Call base class assignment operator
        AForm::operator=(other);
        // Copy derived class members
        this->_target = other._target;
    }
    return *this;
}

// ===== DESTRUCTOR =====
ShrubberyCreationForm::~ShrubberyCreationForm() {
    // Nothing to clean up
}

// ===== GETTER =====
const std::string& ShrubberyCreationForm::getTarget() const {
    return this->_target;
}

// ===== EXECUTE METHOD (Pure virtual implementation) =====
void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
    // STEP 1: Check if form is signed
    if (!this->getIsSigned()) {
        throw AForm::FormNotSignedException();
    }
    
    // STEP 2: Check if executor's grade is high enough
    if (executor.getGrade() > this->getExecGrade()) {
        throw AForm::GradeTooLowException();
    }
    
    // STEP 3: Execute the action
    this->generateShrubbery();
    
    // STEP 4: Print success message (optional, for verification)
    std::cout << "Shrubbery created at " << this->_target << std::endl;
}

// ===== HELPER METHOD =====
void ShrubberyCreationForm::generateShrubbery() const {
    // Create filename: <target>_shrubbery
    std::string filename = this->_target + "_shrubbery";
    
    // Open file for writing
    std::ofstream file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: Could not create file " << filename << std::endl;
        return;
    }
    
    // Write ASCII trees to file
    file << "          .     .  .      +     .      .          ." << std::endl;
    file << "     .       .      .     #       .           ." << std::endl;
    file << "        .      .         ###            .      .      ." << std::endl;
    file << "  .      .#   .      .  #### .        .       ." << std::endl;
    file << "           .       .     #####      .    ." << std::endl;
    file << "    .           .       .########  .     .       ." << std::endl;
    file << "       .      .    .    .####### .        .    ." << std::endl;
    file << "  .      .       .       ######      .     ." << std::endl;
    file << "        .      .        .#######   .       ." << std::endl;
    file << "   .     .    .    .     ######  .        .         ." << std::endl;
    file << "          .       .       ######      .     ." << std::endl;
    file << "       .      .    .    .####### .        .    ." << std::endl;
    file << "  .      .       .       ######      .     ." << std::endl;
    file << "        .      .        .#######   .       ." << std::endl;
    file << "   .     .    .    .     ######  .        .         ." << std::endl;
    file << "          .       .       ######      .     ." << std::endl;
    file << "       .      .    .    .####### .        .    ." << std::endl;
    file << "  .      .       .       ######      .     ." << std::endl;
    file << "        .      .        .#######   .       ." << std::endl;
    file << "   .     .    .    .     ######  .        .         ." << std::endl;
    file << "      .       .         ######      .     ." << std::endl;
    file << "         .     .  .  .  .####. . .         ." << std::endl;
    file << "                  .  . .  .  .           ." << std::endl;
    
    file.close();
    std::cout << "Created: " << filename << " with ASCII trees!" << std::endl;
}