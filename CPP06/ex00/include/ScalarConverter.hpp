#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <cstdlib> // strtod
# include <cctype> 	// isprint()

class ScalarConverter {
private:
	// Orthodox Canonical Form (Private to prevent instantiation and copying)
    ScalarConverter();
    ScalarConverter(const ScalarConverter& src);
    ScalarConverter& operator=(const ScalarConverter& src);
    ~ScalarConverter();

public:
    static void convert(const std::string& literal);
};

#endif