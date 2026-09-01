#include "../include/ScalarConverter.hpp"
#include <iostream>
#include <string> 	// length()
#include <cstdlib>	// std::strtod
#include <cctype> 	// std::isdigit, std::isprint
#include <cmath> 	// std::isnan, std::isinf
#include <climits> 	// INT_MIN, INT_MAX
#include <iomanip> 	// std::fixed, std::setprecision

// Default Constructor
ScalarConverter::ScalarConverter() {}

// Copy Constructor
ScalarConverter::ScalarConverter(const ScalarConverter& src) {
    (void)src; // Prevents unused variable warning if empty
}

// Assignment Operator
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& src) {
    (void)src;
    return *this;
}

// Destructor
ScalarConverter::~ScalarConverter() {}


// Main Function
void ScalarConverter::convert(const std::string& literal) {
    // 1. Detection and handling if it is a direct 'char' (size 1 and not a digit)
    if (literal.length() == 1 && !std::isdigit(literal[0])) {
        char c = literal[0];
        std::cout << "char: '" << c << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
        return;
    }

    // 2. For all other cases: base conversion to double.
    double d = std::strtod(literal.c_str(), NULL);

    // --- CHAR ---
    if (std::isnan(d) || std::isinf(d) || d < 0 || d > 127) {
        std::cout << "char: impossible" << std::endl;
    } else if (std::isprint(static_cast<char>(d))) {
        std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
    } else {
        std::cout << "char: Non displayable" << std::endl;
    }

    // --- INT ---
    if (std::isnan(d) || std::isinf(d) || d < INT_MIN || d > INT_MAX) {
    	std::cout << "int: impossible" << std::endl;
	} else {
    	std::cout << "int: " << static_cast<int>(d) << std::endl;
	}

	// Enables formatting with a fixed decimal place of 1.
	std::cout << std::fixed << std::setprecision(1);

	// --- FLOAT ---
	if (std::isnan(d)) {
		std::cout << "float: nanf" << std::endl;
	} else if (std::isinf(d)) {
		std::cout << "float: " << (d < 0 ? "-inff" : "+inff") << std::endl;
	} else {
		// It prints the number (which already includes a .0) and simply adds an 'f' at the end.
		std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
	}

	// --- DOUBLE ---
	if (std::isnan(d)) {
		std::cout << "double: nan" << std::endl;
	} else if (std::isinf(d)) {
		std::cout << "double: " << (d < 0 ? "-inf" : "+inf") << std::endl;
	} else {
		// Prints the number directly (it automatically includes a .0).
		std::cout << "double: " << static_cast<double>(d) << std::endl;
	}
}