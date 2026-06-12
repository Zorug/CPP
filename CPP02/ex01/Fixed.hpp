# ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream> // operator << overload for std::ostream

/* The objective of this exercise is to create a Fixed 
class THAT WORKS as a fixed-point number. */

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


// ========== NEW CONVERSION MEMBER FUNCTIONS (exercise 01) ==========

// Converts the fixed-point to float.
    float toFloat(void) const;
    
// Converts fixed-point to integer 
    int toInt(void) const;
};

// Overload operator (<<): output fixed-point as a floating.
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif