#include "Fixed.hpp"
#include <iostream>
#include <cmath> // std::roundf

// ========== ORTHODOX CANONICAL FORM ==========

// Default constructor that initializes the fixed-point number to 0.
Fixed::Fixed() : _value(0) {
    std::cout << "Default constructor called" << std::endl;
}

/*  A copy constructor that takes a reference to another Fixed object and
copies its value.*/
Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other; 
}

// A copy assignment operator overload.
Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) { // Check for self-assignment
        this->_value = other.getRawBits();
    }
    return *this; // Return the current object
}

Fixed::~Fixed() { // Destructor
    std::cout << "Destructor called" << std::endl;
}

// ========== ALREADY EXISTING MEMBER FUNCTIONS ==========

// Returns the raw value of the fixed-point.
int Fixed::getRawBits(void) const {
    return this->_value; // Return the raw value of the fixed-point
}

// Sets the raw value of the fixed-point.
void Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called" << std::endl;
    this->_value = raw; // Set the raw value of the fixed-point
}


// ========== NEW CONSTRUCTORS (exercise 01) ==========

// Takes integer and converts it to fixed-point value.
Fixed::Fixed(const int n) {
    std::cout << "Int constructor called" << std::endl;
    // Shift left by the number of fractional bits
    this->_value = n << _fractionalBits;
}

// Takes float and converts it to fixed-point.
Fixed::Fixed(const float f) {
    std::cout << "Float constructor called" << std::endl;
    // Multiply by 2^fractionalBits and round to nearest integer
    this->_value = static_cast<int>(roundf(f * (1 << _fractionalBits)));
}

// ========== NEW CONVERSION MEMBER FUNCTIONS (exercise 01) ==========

// Converts the fixed-point to float.
float Fixed::toFloat(void) const {
// divide the raw value by 2^fractionalBits
    return static_cast<float>(this->_value) / (1 << _fractionalBits); 
}

// Converts fixed-point to integer 
int Fixed::toInt(void) const {
// shift right by the number of fractional bits (truncating fractional part)
    return this->_value >> _fractionalBits;
}

// Overload operator (<<): output fixed-point as a floating.
std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat(); 
    return os; // Return the output stream
}
