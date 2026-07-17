#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>  // For file operations

class ShrubberyCreationForm : public AForm {
private:
    std::string _target;  // Where to create the shrubbery

public:
    // Orthodox Canonical Form
    ShrubberyCreationForm();
    ShrubberyCreationForm(const std::string& target);
    ShrubberyCreationForm(const ShrubberyCreationForm& other);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
    ~ShrubberyCreationForm();

    // Getters
    const std::string& getTarget() const;

    // Implementation of pure virtual function from AForm
    // This is REQUIRED because execute() is pure virtual in AForm
    virtual void execute(const Bureaucrat& executor) const;

    // Helper method to generate ASCII trees
    void generateShrubbery() const;
};

#endif