
#include "../include/Span.hpp"
#include <algorithm>   /* std::sort */
#include <stdexcept>   /* std::out_of_range, std::runtime_error */

/* ======================================================================== */
/*  ORTHODOX CANONICAL FORM                                                 */
/* ======================================================================== */

/*
** Construtor parametrizado.
** Usa a LISTA DE INICIALIZAÇÃO (": _maxSize(N)") para definir a capacidade.
** _numbers não aparece na lista: é construído por defeito (vector vazio).
** O corpo {} está vazio porque não há mais nada a fazer.
*/
Span::Span(unsigned int N) : _maxSize(N) {}

/*
** Construtor de cópia.
** Copia a capacidade e o vector. std::vector já faz CÓPIA PROFUNDA
** (duplica os elementos), por isso não há partilha de memória entre
** objetos e não precisamos de new/delete.
*/
Span::Span(const Span &other) : _maxSize(other._maxSize), _numbers(other._numbers) {}

/*
** Operador de atribuição.
** O teste "this != &other" protege contra auto-atribuição (sp = sp):
** evita trabalho inútil e é um hábito importante quando há recursos
** dinâmicos. Devolve *this para permitir encadeamento (a = b = c).
*/
Span &Span::operator=(const Span &other) {
    if (this != &other) {
        _maxSize = other._maxSize;
        _numbers = other._numbers;   /* vector::operator= copia tudo */
    }
    return *this;
}

/* Destrutor: nada a libertar à mão, o vector limpa-se sozinho (RAII). */
Span::~Span() {}

/* ======================================================================== */
/*  MÉTODOS                                                                 */
/* ======================================================================== */

/*
** addNumber: adiciona um único número.
** Se já temos N (ou mais) elementos, não cabe mais nada -> exceção.
** O limite é imposto aqui porque o vector, por si só, cresceria sem fim.
*/
void Span::addNumber(int number) {
    if (_numbers.size() >= _maxSize) {
        throw std::out_of_range("Span is full ⚠️");
    }
    _numbers.push_back(number);
}

/*
** shortestSpan: menor diferença entre quaisquer dois números.
**
** IDEIA-CHAVE: depois de ORDENAR, os dois números mais próximos entre si
** estão sempre ADJACENTES. Logo, basta comparar vizinhos (O(n)) em vez de
** comparar todos os pares (O(n²)). Com 10 000 números a diferença é enorme.
**
** Complexidade total: O(n log n), dominada pelo sort.
*/
int Span::shortestSpan() const {
    /* Com 0 ou 1 números não existe "distância" -> exceção (pedido no subject). */
    if (_numbers.size() < 2) {
        throw std::runtime_error("Not enough numbers to find a span 📉");
    }

    /*
    ** Trabalhamos numa CÓPIA ordenada. A função é const, logo não pode
    ** alterar _numbers; além disso não queremos mudar a ordem de inserção
    ** original do utilizador.
    */
    std::vector<int> tmp = _numbers;
    std::sort(tmp.begin(), tmp.end());

    /* Ponto de partida: diferença entre os dois primeiros (já ordenados). */
    int minSpan = tmp[1] - tmp[0];

    /*
    ** Percorremos os restantes pares adjacentes (i, i+1).
    ** i < tmp.size() - 1 garante que tmp[i + 1] nunca sai do vector.
    ** (O size >= 2 já foi garantido acima, por isso "size() - 1" não
    ** faz underflow no tipo sem sinal.)
    */
    for (size_t i = 1; i < tmp.size() - 1; ++i) {
        int diff = tmp[i + 1] - tmp[i];   /* >= 0 porque está ordenado */
        if (diff < minSpan) {
            minSpan = diff;
        }
    }
    return minSpan;
}

/*
** longestSpan: maior diferença entre quaisquer dois números.
** É sempre (maior valor) - (menor valor). Depois de ordenar, o menor está
** à frente e o maior no fim.
**
** Nota: também se podia usar std::min_element / std::max_element (O(n),
** sem ordenar), o que seria ainda mais eficiente. Ordenar funciona na mesma.
*/
int Span::longestSpan() const {
    if (_numbers.size() < 2) {
        throw std::runtime_error("Not enough numbers to find a span 📈");
    }
    std::vector<int> tmp = _numbers;
    std::sort(tmp.begin(), tmp.end());
    return tmp.back() - tmp.front();   /* último (maior) - primeiro (menor) */
}
