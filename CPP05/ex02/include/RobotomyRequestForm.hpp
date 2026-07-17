#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>  // For rand()
#include <ctime>    // For time()

class RobotomyRequestForm : public AForm {
private:
    std::string _target;

public:
    // Orthodox Canonical Form
    RobotomyRequestForm();
    RobotomyRequestForm(const std::string& target);
    RobotomyRequestForm(const RobotomyRequestForm& other);
    RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
    ~RobotomyRequestForm();

    // Getters
    const std::string& getTarget() const;

    // Implementation of pure virtual function
    virtual void execute(const Bureaucrat& executor) const;

    // Helper method for robotomy
    void performRobotomy() const;
};

#endif