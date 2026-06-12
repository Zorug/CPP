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

Fixed::Fixed(const float f) {
    std::cout << "Float constructor called" << std::endl;
    // Convert float to fixed-point by multiplying by 2^fractionalBits and rounding to nearest integer
    this->_value = static_cast<int>(roundf(f * (1 << _fractionalBits)));
}

// ========== NEW CONVERSION MEMBER FUNCTIONS (exercise 01) ==========
float Fixed::toFloat(void) const {
    // Convert fixed-point to float by dividing the raw value by 2^fractionalBits
    return static_cast<float>(this->_value) / (1 << _fractionalBits);
}

int Fixed::toInt(void) const {
    // Convert fixed-point to integer by shifting right by the number of fractional bits (truncating the fractional part)
    return this->_value >> _fractionalBits;
}

// Overload of the insertion operator (<<) to output the fixed-point number as a floating-point value.
std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    // Output the fixed-point number as a floating-point value
    os << fixed.toFloat();
    return os; // Return the output stream
}

// ========== NEW OPERATORS (exercise 02) ==========
// Comparison operators: >, <, >=, <=, == and !=.
bool Fixed::operator>(const Fixed& other) const {
    return this->_value > other._value;
}

bool Fixed::operator<(const Fixed& other) const {
    return this->_value < other._value;
}

bool Fixed::operator>=(const Fixed& other) const {
    return this->_value >= other._value;
}

bool Fixed::operator<=(const Fixed& other) const {
    return this->_value <= other._value;
}

bool Fixed::operator==(const Fixed& other) const {
    return this->_value == other._value;
}

bool Fixed::operator!=(const Fixed& other) const {
    return this->_value != other._value;
}

// Arithmetic operators: +, -, *, and /.
Fixed Fixed::operator+(const Fixed& other) const {
    Fixed result;
    result._value = this->_value + other._value;
    return result;
}

Fixed Fixed::operator-(const Fixed& other) const {
    Fixed result;
    result._value = this->_value - other._value;
    return result;
}

Fixed Fixed::operator*(const Fixed& other) const {
    Fixed result;
    // To multiply two fixed-point numbers, we multiply their raw values and then shift right by the number of fractional bits to maintain the fixed-point representation
    // Use long long to prevent overflow during multiplication
    long long temp = static_cast<long long>(this->_value) * static_cast<long long>(other._value);
    result._value = static_cast<int>(temp >> _fractionalBits);
    return result;
}

Fixed Fixed::operator/(const Fixed& other) const {
    Fixed result;
    // To divide two fixed-point numbers, we shift the numerator left by the number of fractional bits before dividing to maintain the fixed-point representation
    // Use long long to prevent overflow during shifting
    // Check for division by zero
    if (other._value == 0) {
        std::cerr << "Error: Division by zero!" << std::endl;
        result._value = 0;
        return result;
    }
    long long temp = (static_cast<long long>(this->_value) << _fractionalBits) / other._value;
    result._value = static_cast<int>(temp);
    return result;
}

// ========== NEW MEMBER FUNCTIONS (exercise 02) ==========

// Increment and decrement operators: both prefix and postfix forms.
Fixed& Fixed::operator++() { // Prefix increment
    this->_value ++; // Increment the fixed-point value by the smallest representable amount (1 in raw value)
    return *this; // Return the current object
}

Fixed Fixed::operator++(int) { // Postfix increment
    Fixed temp(*this); // Create a temporary copy of the current object
    this->_value ++; // Increment the fixed-point value by the smallest representable amount (1 in raw value)
    return temp; // Return the temporary copy (the value before incrementing)
}

Fixed& Fixed::operator--() { // Prefix decrement
    this->_value --; // Decrement the fixed-point value by the smallest representable amount (1 in raw value)
    return *this; // Return the current object
}

Fixed Fixed::operator--(int) { // Postfix decrement
    Fixed temp(*this); // Create a temporary copy of the current object
    this->_value --; // Decrement the fixed-point value by the smallest representable amount (1 in raw value)
    return temp; // Return the temporary copy (the value before decrementing)
}

// Static member functions min and max that return the minimum or maximum of two Fixed objects, respectively. These functions should be overloaded to take either const or non-const references as parameters.
Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a._value < b._value) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a._value < b._value) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a._value > b._value) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a._value > b._value) ? a : b;
}

