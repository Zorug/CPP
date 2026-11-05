/* ************************************************************************** */
/*  ex00 - main.cpp                                                           */
/*                                                                            */
/*  Testes da função template easyfind. Cobrimos 3 cenários:                  */
/*    1. Sucesso num std::vector  (elemento existe)                           */
/*    2. Falha   num std::vector  (elemento não existe -> exceção)            */
/*    3. Sucesso num std::list    (prova que o template é genérico)           */
/* ************************************************************************** */

#include <iostream>   // std::cout, std::endl
#include <vector>     // std::vector  (contentor com memória contígua)
#include <list>       // std::list    (lista duplamente ligada)
#include "easyfind.hpp"

int main() {

    /* ====================================================================== */
    /*  1. TESTE COM std::vector                                              */
    /* ====================================================================== */

    // Em C++98 não existe inicialização com {10, 20, 30}, por isso
    // preenchemos o vector com push_back (acrescenta no fim).
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);

    // --- Cenário de SUCESSO: o valor 20 existe ---------------------------
    // O bloco try "vigia" o código: se easyfind lançar uma exceção, o fluxo
    // salta imediatamente para o catch correspondente.
    try {
        // Como T = std::vector<int>, o retorno é std::vector<int>::iterator.
        // (Em C++98 não há 'auto', temos de escrever o tipo por extenso.)
        std::vector<int>::iterator it = easyfind(vec, 20);

        // *it  = "desreferenciar" o iterador = obter o valor para onde aponta.
        std::cout << "✅ Encontrado no vector: " << *it << std::endl;
    }
    // Apanhamos por referência constante a std::exception, a classe base de
    // todas as exceções da biblioteca standard (inclui runtime_error).
    // Por referência: evita cópia e evita "slicing" (perder o tipo derivado),
    // e e.what() chama a versão correta da mensagem.
    catch (const std::exception &e) {
        std::cout << "❌ Erro: " << e.what() << std::endl;
    }

    // --- Cenário de ERRO: o valor 99 NÃO existe --------------------------
    // Aqui o que queremos testar é precisamente que a exceção é lançada.
    try {
        // Não guardamos o retorno porque não esperamos que chegue a retornar.
        // std::find devolve end() -> easyfind lança runtime_error.
        easyfind(vec, 99);

        // Se chegássemos aqui, algo estaria errado (a exceção não foi lançada).
        std::cout << "❌ Devia ter lançado exceção!" << std::endl;
    } catch (const std::exception &e) {
        // Este é o resultado ESPERADO neste teste.
        std::cout << "⚠️ Exceção capturada com sucesso: " << e.what() << std::endl;
    }

    /* ====================================================================== */
    /*  2. TESTE COM std::list                                                */
    /* ====================================================================== */

    // Mesmo código de easyfind, contentor diferente. Isto demonstra o poder
    // dos templates + iteradores: o algoritmo não sabe (nem precisa de saber)
    // como o contentor guarda os dados, só precisa de begin() e end().
    std::list<int> lst;
    lst.push_back(100);
    lst.push_back(200);

    try {
        // Agora T = std::list<int>, logo o iterador é std::list<int>::iterator.
        std::list<int>::iterator it = easyfind(lst, 100);
        std::cout << "✅ Encontrado na list: " << *it << std::endl;
    } catch (const std::exception &e) {
        std::cout << "❌ Erro: " << e.what() << std::endl;
    }

    // Convenção: 0 = programa terminou sem erros.
    return 0;
}
