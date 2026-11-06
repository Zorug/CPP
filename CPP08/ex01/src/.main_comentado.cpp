/*
** Testes do ex01 (Span):
**   1. Limite de capacidade e exceção ao encher
**   2. shortestSpan / longestSpan (exemplo do subject: deve dar 2 e 14)
**   3. Teste de carga: 10 000 números inseridos por intervalo de iteradores
*/

#include "../include/Span.hpp"
#include <iostream>
#include <vector>

int main() {

    /* ==================================================================== */
    /*  1. TESTE BÁSICO + EXCEÇÃO DE CAPACIDADE                             */
    /* ==================================================================== */
    try {
        Span sp(3);          /* capacidade máxima: 3 números */
        sp.addNumber(10);    /* 1/3 */
        sp.addNumber(3);     /* 2/3 */
        sp.addNumber(20);    /* 3/3 -> cheio */
        sp.addNumber(40);    /* 4.º número: NÃO cabe -> lança out_of_range */

        /* Se chegasse aqui, a exceção não teria sido lançada (falha). */
    } catch (const std::exception &e) {
        /* É o resultado ESPERADO: provamos que o limite é respeitado. */
        std::cout << "✅ Exception caught: " << e.what() << std::endl;
    }

    /* ==================================================================== */
    /*  2. SHORTEST / LONGEST SPAN (exemplo do subject)                     */
    /* ==================================================================== */
    Span sp2(5);
    sp2.addNumber(6);
    sp2.addNumber(3);
    sp2.addNumber(17);
    sp2.addNumber(9);
    sp2.addNumber(11);

    /*
    ** Ordenado: 3, 6, 9, 11, 17
    **   shortest = menor diferença entre vizinhos = 11 - 9 = 2
    **   longest  = 17 - 3 = 14
    **
    ** Estas chamadas estão fora de um try porque sabemos que há 5 números
    ** (>= 2), logo não vão lançar exceção.
    */
    std::cout << "📉 Shortest span: " << sp2.shortestSpan() << std::endl;
    std::cout << "📈 Longest span: " << sp2.longestSpan() << std::endl;

    /* ==================================================================== */
    /*  3. TESTE DE CARGA COM ITERADORES (10 000 ELEMENTOS)                 */
    /* ==================================================================== */
    try {
        Span bigSpan(10000);

        /* Preparamos os dados num vector: 0, 2, 4, ..., 19998. */
        std::vector<int> numbers;
        for (int i = 0; i < 10000; ++i) {
            numbers.push_back(i * 2);
        }

        /*
        ** Inserimos TODOS de uma vez com a versão template de addNumber
        ** (intervalo [begin, end)), em vez de 10 000 chamadas individuais.
        */
        bigSpan.addNumber(numbers.begin(), numbers.end());

        /*
        ** Resultados esperados:
        **   shortest = 2       (todos os vizinhos distam 2)
        **   longest  = 19998   (19998 - 0)
        */
        std::cout << "🚀 BigSpan - Shortest: " << bigSpan.shortestSpan() << std::endl;
        std::cout << "🚀 BigSpan - Longest: " << bigSpan.longestSpan() << std::endl;
    } catch (const std::exception &e) {
        /* Erros inesperados vão para stderr (cerr), por convenção. */
        std::cerr << "❌ Error: " << e.what() << std::endl;
    }

    return 0;
}
