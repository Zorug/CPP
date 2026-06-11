#include "Fixed.hpp"
#include <iostream>

int main(void) {

    Fixed a; // Default constructor called
    // Int constructor called
    // b is initialized to 10 in fixed-point representation
    Fixed const b(10);
    // Float constructor called
    // c is initialized to 42.42 in fixed-point representation
    Fixed const c(42.42f);
    // Copy constructor called
    // d is initialized to the same value as b
    Fixed const d(b);

    // Assignment operator called, a is assigned the value 1234.4321
    // in fixed-point representation
    a = Fixed(1234.4321f);
    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;

    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;

    return 0;
}
