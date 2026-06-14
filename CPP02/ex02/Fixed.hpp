#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream> // operator << overload for std::ostream

/* The objective of this exercise is to create a Fixed 
class THAT WORKS  as a fixed-point number. */ 

class Fixed {
private:
    // Store the fixed-point number.
    int _value;

    // number of bits for the fractional part
    static const int _fractionalBits = 8;

public:
// ========== ORTHODOX CANONICAL FORM ==========
    Fixed(); // constructor

    Fixed(const Fixed& other); // copy constructor

    Fixed& operator=(const Fixed& other); // copy assignment operator

    ~Fixed(); // destructor


// ========== ALREADY EXISTING MEMBER FUNCTIONS ==========

// Returns the raw value of the fixed-point value.
    int getRawBits(void) const;

// Sets the raw value of the fixed-point number.
    void setRawBits(int const raw);


// ========== NEW CONSTRUCTORS (exercise 01) ==========

// Converts integer to the corresponding fixed-point value.
    Fixed(const int n);

// Converts floating-point to fixed-point value.
    Fixed(const float f);


// ======= NEW CONVERSION MEMBER FUNCTIONS (exercise 01) =======

// Converts the fixed-point to float.
    float toFloat(void) const;
// Converts fixed-point to integer 
    int toInt(void) const;


// ========== NEW OPERATORS (exercise 02) ==========
// Comparison operators: >, <, >=, <=, == and !=.
    bool operator>(const Fixed& other) const;
    bool operator<(const Fixed& other) const;
    bool operator>=(const Fixed& other) const;
    bool operator<=(const Fixed& other) const;
    bool operator==(const Fixed& other) const;
    bool operator!=(const Fixed& other) const;

// Arithmetic operators: +, -, *, and /.
    Fixed operator+(const Fixed& other) const;
    Fixed operator-(const Fixed& other) const;
    Fixed operator*(const Fixed& other) const;
    Fixed operator/(const Fixed& other) const;

// Increment and decrement operators
    Fixed& operator++(); // prefix increment operator
    Fixed operator++(int); // postfix increment operator
    Fixed& operator--(); // prefix decrement operator
    Fixed operator--(int); // postfix decrement operator

// Static member functions min and max
    static Fixed& min(Fixed& a, Fixed& b); // min function for non-const references
    static const Fixed& min(const Fixed& a, const Fixed& b); // min function for const references
    static Fixed& max(Fixed& a, Fixed& b); // max function for non-const references
    static const Fixed& max(const Fixed& a, const Fixed& b); // max function for const references
};

// Overload of the insertion operator (<<) to output the fixed-point number as a floating-point value.
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif