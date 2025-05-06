/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaucher <amaucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:22:27 by amaucher          #+#    #+#             */
/*   Updated: 2024/09/13 10:51:35 by amaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// Default constructor
ScalarConverter::ScalarConverter(void) {}

// Copy constructor
ScalarConverter::ScalarConverter(ScalarConverter const &src) {
    (void)src;
}

// Copy assignment operator
ScalarConverter &ScalarConverter::operator=(ScalarConverter const &src) {
    (void)src;
    return *this;
}

// Destructor
ScalarConverter::~ScalarConverter(void) {}

// print the conversion
static void	printConversion(double d)
{
	char c = static_cast<char>(d); //? what is happening
	int i = static_cast<int>(d);
	float f = static_cast<float>(d);

	//char
	// "isnan" = is not a number; CHAR_MAX = 127; CHAR_MIN = -128
	std::cout << "char: ";
	if (std::isnan(d) || d > CHAR_MAX || d < CHAR_MIN)
		std::cout << "impossible" << std::endl;
	else {
		if (!std::isprint(c))
			std::cout << "Non displayable" <<std::endl;
		else
			std::cout << "'" << c << "'" << std::endl;
	}

	//int
	std::cout << "int: ";
	if (std::isnan(d) || d > INT_MAX || d < INT_MIN)
		std::cout << "impossible" << std::endl;
	else
		std::cout << i << std::endl;

	//float
	std::cout << "float: ";
	if (!std::isinf(d) && (d > std::numeric_limits<float>::max() || d < -std::numeric_limits<float>::max() || std::isnan(d)))
		std::cout << "impossible" << std::endl;
	// setprecision = 1 means one decimal place
	else
		std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;

	//double
	std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

void	ScalarConverter::convert(std::string literal)
{
	double	d; // stores the converted value
	char *endptr; // used by strtod to indicate where the conversion stopped
	
	// check if the input is exactly one character long and not a digit (e.g. 'a', 'f', 'g', etc.)
	if (literal.size() == 1 && !std::isdigit(literal[0])) // s[0] is 'a' and will then be converted ascii
		d = literal[0];
	// "nan" = not a number 
	else if (literal == "nan")
		d = std::numeric_limits<double>::quiet_NaN();
	// ff for float compatibility
	else if (literal == "+inf" || literal == "+inff")
		d = std::numeric_limits<double>::infinity();
	else if (literal == "-inf" || literal == "-inff")
		d = -std::numeric_limits<double>::infinity();
	else {
		// check for float (e.g. 42.42f and if found remove the f)
		if (literal[literal.size() - 1] == 'f')
			literal.erase(literal.end() - 1, literal.end());
		// convert the string to a double
		d = std::strtod(literal.c_str(), &endptr);
		if (*endptr != '\0') {
			std::cerr << "Conversion failed." << std::endl;
			return ;
		}
	}
	printConversion(d);
}