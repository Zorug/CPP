/*
** ex01 - Span
**
** Classe que guarda no máximo N inteiros e sabe calcular a menor e a maior
** distância (span) entre quaisquer dois dos números guardados.
*/

/* INCLUDE GUARDS: evitam a dupla inclusão deste header. */
#ifndef SPAN_HPP
#define SPAN_HPP

/*
** DEPENDÊNCIAS (o header deve ser autossuficiente):
**  - <vector>    : std::vector, o contentor onde guardamos os números.
**  - <algorithm> : algoritmos da STL (usados nos .cpp e por coerência aqui).
**  - <iterator>  : std::distance, usado no template abaixo.
**  - <stdexcept> : std::out_of_range, a exceção lançada quando o Span enche.
*/
#include <vector>
#include <algorithm>
#include <iterator>
#include <stdexcept>

class Span {
private:
    /*
    ** _maxSize : capacidade máxima (N), definida no construtor e fixa.
    ** _numbers : os números realmente guardados.
    **
    ** Porque std::vector? Cresce dinamicamente (push_back/insert), aceita
    ** inserção por intervalo de iteradores e ainda por cima gere a sua
    ** própria memória, por isso não precisamos de new/delete nem há leaks.
    ** O limite N é imposto por nós, não pelo vector.
    */
    unsigned int _maxSize;
    std::vector<int> _numbers;

public:
    /* ---------------------------------------------------------------- */
    /*  ORTHODOX CANONICAL FORM (obrigatório do módulo 02 ao 09)         */
    /*  1. Construtor (aqui, parametrizado: recebe N)                    */
    /*  2. Construtor de cópia                                           */
    /*  3. Operador de atribuição                                        */
    /*  4. Destrutor                                                     */
    /* ---------------------------------------------------------------- */
    Span(unsigned int N);
    Span(const Span &other);
    Span &operator=(const Span &other);
    ~Span();

    /* ---------------------------------------------------------------- */
    /*  MÉTODOS PRINCIPAIS                                               */
    /* ---------------------------------------------------------------- */

    /* Adiciona UM número. Lança exceção se o Span já estiver cheio. */
    void addNumber(int number);

    /*
    ** Adiciona VÁRIOS números de uma vez, a partir de um intervalo de
    ** iteradores [begin, end). É o "bónus" pedido pelo subject.
    **
    ** Porque é um template?
    **   O intervalo pode vir de um vector, de uma list, de um deque, de um
    **   array normal... Ao receber 'Iterator' genérico, aceitamos todos.
    **
    ** Porque está implementado no header?
    **   Templates têm de estar visíveis no momento em que são instanciados.
    **   É a exceção à regra "sem implementações em headers".
    **
    ** É uma SOBRECARGA de addNumber(int): quando chamas addNumber(10) o
    ** compilador escolhe a versão normal (1 argumento); com 2 argumentos
    ** escolhe esta.
    */
    template <typename Iterator>
    void addNumber(Iterator begin, Iterator end) {
        /*
        ** Verificamos ANTES de inserir se vai caber tudo:
        **   (quantos já tenho) + (quantos vou adicionar) > capacidade ?
        **
        ** std::distance(begin, end) devolve quantos elementos há no
        ** intervalo (tipo com sinal), por isso o static_cast<size_t> para
        ** o comparar com size() sem avisos de sinal (-Wextra -Werror).
        **
        ** Validar primeiro garante a "garantia forte" de exceções: se não
        ** couber, o Span fica intacto (não inserimos metade dos números).
        */
        if (_numbers.size() + static_cast<size_t>(std::distance(begin, end)) > _maxSize) {
            throw std::out_of_range("Span is full ⚠️");
        }
        /*
        ** vector::insert(posição, first, last) copia o intervalo todo para
        ** o fim do vector numa única chamada (mais eficiente do que
        ** milhares de addNumber individuais).
        */
        _numbers.insert(_numbers.end(), begin, end);
    }

    /* ---------------------------------------------------------------- */
    /*  CÁLCULO DOS SPANS                                                */
    /*  'const' no fim: estas funções não modificam o objeto.            */
    /* ---------------------------------------------------------------- */
    int shortestSpan() const;   /* menor diferença entre dois números  */
    int longestSpan() const;    /* maior diferença (max - min)         */
};

#endif
