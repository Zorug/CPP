#ifndef FIXED_HPP
# define FIXED_HPP

/*create a class that works as a fixed-point number*/
class Fixed {
private:
// An integer to store the fixed-point number value.
    int _value; // store de fixed value

// number of bits for the fractional part
    static const int _fractionalBits = 8;
        
public:
// Orthodox Canonical Form:
    Fixed(); // default constructor (_value = 0)

    Fixed(const Fixed& other); // copy constructor

    Fixed& operator=(const Fixed& other); // copy assignment operator

    ~Fixed(); // destructor

// Member functions:
// Returns the raw value of the fixed-point value.
    int getRawBits(void) const;

// Sets the raw value of the fixed-point number.
    void setRawBits(int const raw);
};

#endif