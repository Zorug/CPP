#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <cstdlib> // strtod
# include <cctype> 	// isprint()

class ScalarConverter {
/*
If we leave the constructors in public:, anyone can do ScalarConverter obj; in main(). 
By placing the constructors in private:, the compiler prohibits the creation of instances. 
Therefore, we keep the OCF declared in private:!
*/
private:
	// Orthodox Canonical Form (Private to prevent instantiation and copying)
    ScalarConverter();
    ScalarConverter(const ScalarConverter& src);
    ScalarConverter& operator=(const ScalarConverter& src);
    ~ScalarConverter();

public:
	// Only required public static method
    static void convert(const std::string& literal);
};

#endif