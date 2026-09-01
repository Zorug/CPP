#include "../include/ScalarConverter.hpp"
#include <iostream>

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Usage: ./convert <literal>" << std::endl;
        return 1;
    }
    ScalarConverter::convert(argv[1]);
    return 0;
}

/*
** =============================================================================
**                          ScalarConverter Test Cases
** =============================================================================
** Usage: ./ex00 <literal>
**
** 1. CHAR LITERALS:
**    ./ex00 'a'          -> Printable character
**    ./ex00 '*'          -> Printable special character
**
** 2. INT LITERALS:
**    ./ex00 0            -> Non-displayable char (ASCII 0)
**    ./ex00 42           -> Printable char (ASCII 42 = '*')
**    ./ex00 2147483647   -> Maximum integer value (INT_MAX)
**    ./ex00 -2147483648  -> Minimum integer value (INT_MIN)
**
** 3. FLOAT LITERALS:
**    ./ex00 0.0f         -> Float zero
**    ./ex00 42.0f        -> Float integer equivalent
**    ./ex00 4.2f         -> Float decimal
**    ./ex00 nanf         -> Float NaN pseudo-literal
**    ./ex00 -inff        -> Float negative infinity pseudo-literal
**    ./ex00 +inff        -> Float positive infinity pseudo-literal
**
** 4. DOUBLE LITERALS:
**    ./ex00 0.0          -> Double zero
**    ./ex00 42.0         -> Double integer equivalent
**    ./ex00 4.2          -> Double decimal
**    ./ex00 nan          -> Double NaN pseudo-literal
**    ./ex00 -inf         -> Double negative infinity pseudo-literal
**    ./ex00 +inf         -> Double positive infinity pseudo-literal
**
** 5. OVERFLOW / IMPOSSIBLE CASES:
**    ./ex00 2147483648   -> Overflow for int (> INT_MAX)
**    ./ex00 -2147483649  -> Underflow for int (< INT_MIN)
** =============================================================================
*/