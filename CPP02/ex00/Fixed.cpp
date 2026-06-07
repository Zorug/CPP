#include "Fixed.hpp"
#include <iostream> // std::cout, std::endl

// Default constructor that initializes the fixed-point number to 0.
Fixed::Fixed() : _value(0) {
    std::cout << "Default constructor called" << std::endl;
}

/*  A copy constructor that takes a reference to another Fixed object and
copies its value.
    This must be define to avoid default copy constructor made in C++.
    In C++, if you do not define a copy constructor, the compiler will 
generate a default one for you. However, the default copy constructor 
performs a shallow copy, which may not be suitable for classes that manage 
resources (like dynamic memory). By defining your own copy constructor, 
you can ensure that the copying process is done correctly, especially if 
your class has pointers or other resources that require deep copying. */
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

// A member function int getRawBits( void ) const;
// that returns the raw value of the fixed-point value.
int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->_value; // Return the raw value of the fixed-point number
}

// A member function void setRawBits( int const raw );
// that sets the raw value of the fixed-point number.
void Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called" << std::endl;
    this->_value = raw; // Set the raw value of the fixed-point number
}