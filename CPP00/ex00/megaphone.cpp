/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 22:02:50 by cgross-s          #+#    #+#             */
/*   Updated: 2026/03/16 22:52:53 by cgross-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream> // saída, como stdio.h
#include <cctype>

int main (int argc, char **args)
{
	// Sem argumentos: imprime o ruido padrao pedido no enunciado.
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	// Percorre cada argumento (ignorando args[0], que e o nome do programa).
	for (int i = 1; i < argc; i += 1)
		// Converte cada caractere para maiuscula antes de imprimir.
		for (int j = 0; args[i][j]; j += 1)
			std::cout << static_cast<char>(
				std::toupper(static_cast<unsigned char>(args[i][j])));
	std::cout << std::endl;
	return 0;
}
