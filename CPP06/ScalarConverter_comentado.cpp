#include "../include/ScalarConverter.hpp"
#include <iostream>
#include <string> 	// length()
#include <cstdlib>	// std::strtod
#include <cctype> 	// std::isdigit, std::isprint
#include <cmath> 	// std::isnan, std::isinf
#include <climits> 	// INT_MIN, INT_MAX
#include <iomanip> 	// std::fixed, std::setprecision

// A classe não guarda nenhum estado (nenhum atributo), então os construtores,
// o operator= e o destrutor não precisam fazer nada de fato.
// Eles existem só para respeitar a Orthodox Canonical Form pedida no subject.

// Construtor por defeito
ScalarConverter::ScalarConverter() {}

// Construtor por cópia
ScalarConverter::ScalarConverter(const ScalarConverter& src) {
    (void)src; // Evita warning de "parâmetro não usado", já que não há nada a copiar
}

// Operador de atribuição
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& src) {
    (void)src;
    return *this;
}

// Destrutor
ScalarConverter::~ScalarConverter() {}


// Função principal (único método static da classe, conforme pedido no subject)
void ScalarConverter::convert(const std::string& literal) {
    // -----------------------------------------------------------------
    // 1. CASO ESPECIAL: literal de char "puro"
    // -----------------------------------------------------------------
    // Se a string tem exatamente 1 caractere E esse caractere NÃO é um
    // dígito, assumimos que o utilizador quis dizer um char literal
    // (ex: "a", "c", "$"...). Isto exclui "5", que tem 1 caractere mas
    // é um dígito e deve ser tratado como int mais abaixo.
    if (literal.length() == 1 && !std::isdigit(literal[0])) {
        char c = literal[0];

        // Aqui usamos static_cast (o cast escolhido para o exercício,
        // conforme pedido na "Additional Rule" do subject) para converter
        // o char explicitamente para os outros tipos.
        std::cout << "char: '" << c << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
        return; // Já tratámos este caso, não continuamos para a lógica de baixo
    }

    // -----------------------------------------------------------------
    // 2. CASO GERAL: int, float, double e pseudo-literais (nan/inf)
    // -----------------------------------------------------------------
    // std::strtod converte a string para double e, de forma prática,
    // já sabe interpretar "nan", "nanf", "inf", "+inf", "-inf", "inff", etc.
    // Isto poupa-nos de ter de fazer o parsing manual desses casos especiais.
    // (NULL é passado porque não precisamos de saber onde parou a conversão.)
    double d = std::strtod(literal.c_str(), NULL);

    // --- CHAR ---
    // Um double só pode virar char válido se:
    //  - não for NaN
    //  - não for infinito
    //  - estiver dentro do range [0, 127] (range de um char ASCII "normal")
    if (std::isnan(d) || std::isinf(d) || d < 0 || d > 127) {
        std::cout << "char: impossible" << std::endl;
    } else if (std::isprint(static_cast<char>(d))) {
        // isprint verifica se o char resultante é "imprimível" (visível)
        std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
    } else {
        // É um char válido (0-127) mas não imprimível (ex: caracteres de controlo)
        std::cout << "char: Non displayable" << std::endl;
    }

    // --- INT ---
    // Um double só pode virar int válido se não for NaN/infinito e
    // estiver dentro dos limites de um int (INT_MIN a INT_MAX, de <climits>)
    if (std::isnan(d) || std::isinf(d) || d < INT_MIN || d > INT_MAX) {
    	std::cout << "int: impossible" << std::endl;
	} else {
    	std::cout << "int: " << static_cast<int>(d) << std::endl;
	}

	// A partir daqui, ativa-se a formatação com 1 casa decimal fixa,
	// para que os floats/doubles sejam sempre impressos como "42.0"
	// em vez de, por exemplo, "42" (sem casas decimais).
	std::cout << std::fixed << std::setprecision(1);

	// --- FLOAT ---
	// Float e double nunca são "impossible": eles conseguem representar
	// NaN e infinito nativamente, então tratamos esses casos à parte,
	// em vez de dizer que é impossível.
	if (std::isnan(d)) {
		std::cout << "float: nanf" << std::endl;
	} else if (std::isinf(d)) {
		std::cout << "float: " << (d < 0 ? "-inff" : "+inff") << std::endl;
	} else {
		// static_cast<float> faz a conversão explícita de double -> float
		// (pode haver perda de precisão, mas isso é esperado/normal aqui)
		std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
	}

	// --- DOUBLE ---
	// Aqui já não é preciso cast nenhum porque 'd' já é um double,
	// mas mantemos static_cast<double> por clareza/consistência com o resto.
	if (std::isnan(d)) {
		std::cout << "double: nan" << std::endl;
	} else if (std::isinf(d)) {
		std::cout << "double: " << (d < 0 ? "-inf" : "+inf") << std::endl;
	} else {
		std::cout << "double: " << static_cast<double>(d) << std::endl;
	}
}
