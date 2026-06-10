#include "Fixed.hpp"
#include <iostream>

// Default constructor: initializes the fixed-point number to 0.
Fixed::Fixed() : _value(0) {
    std::cout << "Default constructor called" << std::endl;
}

//  A copy constructor that takes a reference to another Fixed 
// object and copies its value. To ensure that the copying process is 
// done correctly.
Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;  // Use the copy assignment operator to copy the value
}

// A copy assignment operator overload.
/*  a ---------> other
    b ---------> this */
Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) { // Check for self-assignment
        this->_value = other.getRawBits(); // Copy the raw value
    }
    return *this; // Return the current object
}

// A destructor.
Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

// Member functions:
// Returns the raw value of the fixed-point value.
int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->_value;
}

// Sets the raw value of the fixed-point number.
void Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called" << std::endl;
    this->_value = raw;
}