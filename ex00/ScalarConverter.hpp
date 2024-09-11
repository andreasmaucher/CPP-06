/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaucher <amaucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:22:27 by amaucher          #+#    #+#             */
/*   Updated: 2024/09/11 22:56:23 by amaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP

# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <limits>
#include <limits.h>
#include <sstream>
#include <cstring>
#include <numeric>
#include <cmath>

// if a class is purely static and non-instantiable orthodox canonical form
// functions are not needed
// Destructor: no objects to destroy, since no instances can be created
// Copy Constructor: no objects can be created so no need to copy or assign

class ScalarConverter
{	
	public:
			
			// only one static method convert
			static void convert(std::string literal);
		
	private:
			// constructor private to make the class non instantiable
			ScalarConverter(void);
		
};

#endif