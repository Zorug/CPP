#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream> // operator << overload for std::ostream

/* In this exercise, you will create a Fixed class THAT WORKS 
as a fixed-point number. */ 

class Fixed {
private:
    // An integer to store the fixed-point number value.
    int _value; // store de fixed value
    /*static constant integer to store the number of fractional bits. 
Its value will always be the integer literal 8.*/
    static const int _fractionalBits = 8; // number of bits for the fractional

public:
    // Orthodox Canonical Form:
    // Default constructor that initializes the fixed-point number to 0.
    Fixed(); // default constructor
    // A copy constructor that takes a reference to another Fixed object and copies its value.
    Fixed(const Fixed& other); // copy constructor
    // A copy assignment operator overload.
    Fixed& operator=(const Fixed& other); // copy assignment operator
    // A destructor.
    ~Fixed(); // destructor

    // NEW CONSTRUCTORS (exercise 01):
    // A constructor that takes a constant integer as a parameter and converts it to the corresponding fixed-point value.
    Fixed(const int n); // constructor from integer
    // A constructor that takes a constant floating-point number as a parameter and converts it to the corresponding fixed-point value.
    Fixed(const float f); // constructor from float

    // NEW CONVERSION MEMBER FUNCTIONS (exercise 01):
    // A member function float toFloat( void ) const; that converts the fixed-point value to a floating-point number.
    float toFloat(void) const; // convert the fixed-point value to a floating-point number
    // A member function int toInt( void ) const; that converts the fixed-point value to an integer (by truncating the fractional part).
    int toInt(void) const; // convert the fixed-point value to an integer (by truncating the fractional part

    // Member functions:
    /* A member function int getRawBits( void ) const;
    that returns the raw value of the fixed-point value. */
    int getRawBits(void) const; // return the raw value of the fixed-point number
    /* A member function void setRawBits( int const raw );
    that sets the raw value of the fixed-point number. */
    void setRawBits(int const raw); // set the raw value of the fixed-point number

    // NEW OPERATORS (exercise 02):
    // Comparison operators: >, <, >=, <=, == and !=.
    bool operator>(const Fixed& other) const; // greater than operator
    bool operator<(const Fixed& other) const; // less than operator
    bool operator>=(const Fixed& other) const; // greater than or equal to operator
    bool operator<=(const Fixed& other) const; // less than or equal to operator
    bool operator==(const Fixed& other) const; // equality operator
    bool operator!=(const Fixed& other) const; // inequality operator

    // Arithmetic operators: +, -, *, and /.
    Fixed operator+(const Fixed& other) const; // addition operator
    Fixed operator-(const Fixed& other) const; // subtraction operator
    Fixed operator*(const Fixed& other) const; // multiplication operator
    Fixed operator/(const Fixed& other) const; // division operator

    // Increment and decrement operators: both prefix and postfix forms.
    Fixed& operator++(); // prefix increment operator
    Fixed operator++(int); // postfix increment operator
    Fixed& operator--(); // prefix decrement operator
    Fixed operator--(int); // postfix decrement operator

    // Static member functions min and max that take two references to Fixed objects and return a reference to the smaller (for min) or larger (for max) of the two objects. These functions should be overloaded to take either const or non-const references.
    static Fixed& min(Fixed& a, Fixed& b); // min function for non-const references
    static const Fixed& min(const Fixed& a, const Fixed& b); // min function for const references
    static Fixed& max(Fixed& a, Fixed& b); // max function for non-const references
    static const Fixed& max(const Fixed& a, const Fixed& b); // max function for const references
};

// Overload of the insertion operator (<<) to output the fixed-point number as a floating-point value.
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif