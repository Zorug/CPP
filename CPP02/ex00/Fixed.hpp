#ifndef FIXED_HPP
# define FIXED_HPP

//# include <iostream>
//# include <string>

/*create a class that works as a fixed-point number*/
class Fixed {
private:
    // An integer to store the fixed-point number value.
    int _value; // store de fixed value

    /*static constant integer to store the number of fractional bits. Its value
    will always be the integer literal 8.*/
    static const int _fractionalBits = 8; // number of bits for the fractional part
        
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

    // Member functions:
    /* A member function int getRawBits( void ) const;
    that returns the raw value of the fixed-point value. */
    int getRawBits(void) const; // return the raw value of the fixed-point number

    /* A member function void setRawBits( int const raw );
    that sets the raw value of the fixed-point number. */
    void setRawBits(int const raw); // set the raw value of the fixed-point number
};

#endif