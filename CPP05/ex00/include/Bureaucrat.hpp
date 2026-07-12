#ifndef BUREUCRAT_HPP
#define BUREUCRAT_HPP

#include <iostream>
#include <string>
#include <exception> // std::exception

class Bureaucrat
{
private:
	const	std::string _name;
	int		_grade;
public:
	// Orthodox Canonical Form
	Bureaucrat();
	Bureaucrat(const std::string& name, int grade);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);
	~Bureaucrat();

	// Getters - read but not modify
	// const means that the functions doesnt modify the object
	// & avoids unecessary copy of the string
	const std::string& getName() const;
	int getGrade() const;

	// Methods that change the grade
	void incrementGrade();
	void decrementGrade();

	// Nested Exceptions - Class inside another class
	// std::exception is the base class to all exceptions in C++
	class GradeTooHighException : public std::exception {
	public:
		// Method that returns the error message.
		// throw() means that this function dont make exceptions
		virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
};

// Operator overload
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif