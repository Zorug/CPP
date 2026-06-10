#include <iostream>
#include "Fixed.hpp"

int main( void ) {

    Fixed a; // Default constructor called
    // COPY CONSTRUCTOR called - new object b
    Fixed b( a ); // equivalent to Fixed b = a;
    Fixed c; // Default constructor called

    // COPY ASSIGNMENT operator called
    // the object c is already created
    c = b;

    // getRawBits member function called
    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;

    return 0;
}