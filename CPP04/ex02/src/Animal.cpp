#include "../include/Animal.hpp"

// Default constructor
Animal::Animal() : type("Animal")
{
    std::cout << "Animal default constructor called" << std::endl;
}

// Copy constructor
Animal::Animal(const Animal& other)
{
    std::cout << "Animal copy constructor called" << std::endl;
    *this = other;
}

// Assignment operator
Animal& Animal::operator=(const Animal& other)
{
    std::cout << "Animal assignment operator called" << std::endl;
    if (this != &other)
        this->type = other.type;
    return *this;
}

// Virtual destructor
Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
}

// Regular member function
std::string Animal::getType() const
{
    return this->type;
}

// NOTE: makeSound() is NOT implemented here!
// It's pure virtual, so we don't provide a body.
// This makes Animal an ABSTRACT class.