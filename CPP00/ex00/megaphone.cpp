/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 20:31:13 by cgross-s          #+#    #+#             */
/*   Updated: 2026/05/07 21:48:12 by cgross-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>	// cout
#include <cctype>	// toupper

int main(int argc, char **argv)
{

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";

	else if (argc > 1) {
		for(int i = 1; i < argc; i++) { // here we are passing word by word

			for(int j = 0; argv[i][j]; j++) { // here we are passing letter to letter

			/*	std::toupper() waits for: unsigned char and argv is char type
				static_cast is an operator that performs an explicit type conversion.
				toupper returns an int, so it need to be converted back to char */
				
				std::cout << static_cast<char>(
					std::toupper(static_cast<unsigned char>(argv[i][j])));
			}
		}
	}
	std::cout << '\n';

	return 0;
}