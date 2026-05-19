/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 21:16:09 by cgross-s          #+#    #+#             */
/*   Updated: 2026/05/19 22:26:07 by cgross-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
1. Verificar se temos 3 parâmetros (filename, s1, s2)
2. Abrir arquivo de entrada (ifstream)
3. Se não abrir → erro
4. Criar arquivo de saída (ofstream) com nome filename + ".replace"
5. Ler arquivo linha por linha (ou todo de uma vez)
6. Para cada linha:
   - Encontrar todas as ocorrências de s1
   - Substituir por s2 (manualmente)
   - Escrever no arquivo de saída
7. Fechar os arquivos (destrutores fazem isso automaticamente)
*/

#include <fstream>	//ifstream (ler), ofstream (escrever)
#include <iostream>	//std::cerr
#include <string>	//std::string, find(), substr()

int main(int argc, char **argv)
{
	//(void)argv;
	if(argc != 4) {
		std::cout << "You must have 3 arguments.\nYou shall not pass!\n";
		return 0;
	}

	// Abrir arquivo de entrada (ifstream)
	// inputFile é um objeto de std::ifstream, que abre o arquivo automaticamente
	std::ifstream inputFile(argv[1]);
	if(!inputFile) {
		std::cerr << "Error: Could not open file " << argv[1] << std::endl;
		return 1;
	}

	// Criar arquivo de saída (ofstream) com nome filename + ".replace"
	std::string outputFileName = argv[1];
	outputFileName += ".replace";

	std::ofstream outputFile(outputFileName.c_str()); //*.c_str converte para cnt_str
	if (!outputFile) {
		std::cerr << "Error: Could not create output file " << outputFileName << std::endl;
		return 1;
	}

	// Ler arquivo linha por linha (ou todo de uma vez)
	std::string line;
	while (std::getline(inputFile, line)) {
		//
		outputFile << line << std::endl;
	}


}
