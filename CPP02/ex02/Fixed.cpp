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
        this->_value = other.getRawBits();
    }
    return *this; // Return the current object
}

// A destructor.
Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

// ========== ALREADY EXISTING MEMBER FUNCTIONS ==========

// Returns the raw value of the fixed-point.
int Fixed::getRawBits(void) const {
    return this->_value;
}

// Sets the raw value of the fixed-point.
void Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called" << std::endl;
    this->_value = raw;
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

// Fixed(5.05f).operator*(Fixed(2))
Fixed Fixed::operator*(const Fixed& other) const {
    Fixed result;
    // To multiply two fixed-point numbers, we multiply their raw values and then shift 
    // right by the number of fractional bits to maintain the fixed-point representation
    // Use long long to prevent overflow during multiplication
    long long temp = static_cast<long long>(this->_value) * static_cast<long long>(other._value);
    result._value = static_cast<int>(temp >> _fractionalBits); // /256
    return result;
}

Fixed Fixed::operator/(const Fixed& other) const {
    Fixed result;
    // To divide two fixed-point numbers, we shift the numerator left by the 
    // number of fractional bits before dividing to maintain the fixed-point 
    // representation
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

// Static member functions min and max that return the minimum or maximum 
// of two Fixed objects, respectively. These functions should be overloaded 
// to take either const or non-const references as parameters.
Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a._value < b._value) ? a : b;
}

// condição ? valor_se_true : valor_se_false
const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a._value < b._value) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a._value > b._value) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a._value > b._value) ? a : b;
}
