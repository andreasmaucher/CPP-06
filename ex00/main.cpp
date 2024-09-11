/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaucher <amaucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:22:27 by amaucher          #+#    #+#             */
/*   Updated: 2024/09/11 23:13:47 by amaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

//! update

int	main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cout << "Input: ./scalarconv <literal to convert>" << std::endl;
		return (0);
	}
	ScalarConverter::convert(argv[1]);
	return (0);
}
