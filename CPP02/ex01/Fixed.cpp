#include "Fixed.hpp"
#include <iostream>
#include <cmath> // std::roundf for rounding float to nearest integer

// ========== ORTHODOX CANONICAL FORM ==========

// Default constructor that initializes the fixed-point number to 0.
Fixed::Fixed() : _value(0) {
    std::cout << "Default constructor called" << std::endl;
}

/*  A copy constructor that takes a reference to another Fixed object and
copies its value.*/
Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;  // Use the copy assignment operator to copy the value
}

// A copy assignment operator overload.
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

// ========== ALREADY EXISTING MEMBER FUNCTIONS ==========
// A member function int getRawBits( void ) const;
// that returns the raw value of the fixed-point value.
int Fixed::getRawBits(void) const {
    //std::cout << "getRawBits member function called" << std::endl;
    return this->_value; // Return the raw value of the fixed-point number
}

// A member function void setRawBits( int const raw );
// that sets the raw value of the fixed-point number.
void Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called" << std::endl;
    this->_value = raw; // Set the raw value of the fixed-point number
}

// ========== NEW CONSTRUCTORS (exercise 01) ==========
// A constructor that takes a constant integer as a parameter and converts 
// it to the corresponding fixed-point value.
Fixed::Fixed(const int n) {
    std::cout << "Int constructor called" << std::endl;
    // Convert integer to fixed-point by shifting left by the 
    // number of fractional bits
    this->_value = n << _fractionalBits;
}

// A constructor that takes a constant floating-point number as a 
// parameter and converts it to the corresponding fixed-point value.
Fixed::Fixed(const float f) {
    std::cout << "Float constructor called" << std::endl;
    // Convert float to fixed-point by multiplying by 2^fractionalBits 
    // and rounding to nearest integer
    this->_value = static_cast<int>(roundf(f * (1 << _fractionalBits)));
}

// ========== NEW CONVERSION MEMBER FUNCTIONS (exercise 01) ==========
// A member function float toFloat( void ) const; that converts the 
// fixed-point value to a floating-point number.
float Fixed::toFloat(void) const {
    // Convert fixed-point to float by dividing the raw value by 
    // 2^fractionalBits
    return static_cast<float>(this->_value) / (1 << _fractionalBits); 
}

// A member function int toInt( void ) const; that converts the 
// fixed-point value to an integer (by truncating the fractional part).
int Fixed::toInt(void) const {
    // Convert fixed-point to integer by shifting right by the number of 
    // fractional bits (truncating the fractional part)
    return this->_value >> _fractionalBits;
}

// Overload of the insertion operator (<<) to output the fixed-point 
// number as a floating-point value.
std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    // Output the fixed-point number as a floating-point value
    os << fixed.toFloat(); 
    return os; // Return the output stream
}
