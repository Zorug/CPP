#pragma once

#include <iostream>

class ScalarConverter
{
public:
//OCF
	ScalarConverter();
	ScalarConverter(const ScalarConverter& src);
	ScalarConverter& operator=(const ScalarConverter& src);
	~ScalarConverter();

	static void convert(const std::string& literal);
};
