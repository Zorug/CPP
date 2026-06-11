# ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream> // operator << overload for std::ostream

/* In this exercise, you will create a Fixed class THAT WORKS 
as a fixed-point number. */

class Fixed {
private:
    // An integer to store the fixed-point number value.
    int _value;

    // number of bits for the fractional part
    static const int _fractionalBits = 8;

public:
    // Orthodox Canonical Form:
    Fixed(); // default constructor

    Fixed(const Fixed& other); // copy constructor

    Fixed& operator=(const Fixed& other); // copy assignment operator

    ~Fixed(); // destructor

// ===== NEW CONSTRUCTORS (exercise 01) =====
// Converts integer to the corresponding fixed-point value.
    Fixed(const int n);

// Converts floating-point to fixed-point value.
    Fixed(const float f);

// NEW CONVERSION MEMBER FUNCTIONS (exercise 01):
// converts the fixed-point value to a floating-point number.
    float toFloat(void) const; // convert the fixed-point value to a floating-point number
    
// converts the fixed-point value to an integer (by truncating 
// the fractional part).
    int toInt(void) const; // convert the fixed-point value to an integer (by 
    // truncating the fractional part

// Member functions:
// Returns the raw value of the fixed-point value.
    int getRawBits(void) const;

// Sets the raw value of the fixed-point number.
    void setRawBits(int const raw);
};

// Overload of the insertion operator (<<) to output the fixed-point 
// number as a floating-point value.
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif