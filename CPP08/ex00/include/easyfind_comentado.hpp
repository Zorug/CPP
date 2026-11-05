/* ************************************************************************** */
/*  ex00 - easyfind.hpp                                                       */
/*                                                                            */
/*  Objetivo: procurar a PRIMEIRA ocorrência de um inteiro dentro de um       */
/*  contentor de inteiros (vector, list, deque...).                           */
/* ************************************************************************** */

/*
** INCLUDE GUARDS
** Evitam a "dupla inclusão": se este header for incluído duas vezes na mesma
** unidade de compilação, o pré-processador salta o conteúdo à segunda vez.
** O subject exige isto (sem guards = nota 0).
*/
#ifndef EASYFIND_HPP
#define EASYFIND_HPP

/*
** DEPENDÊNCIAS
** Cada header deve incluir tudo aquilo de que precisa (regra do subject),
** para poder ser usado sozinho, sem depender da ordem dos includes do main.
**
**  - <algorithm> : fornece std::find (o algoritmo da STL que vamos usar).
**  - <stdexcept> : fornece std::runtime_error (a exceção que vamos lançar).
**
** Nota: este módulo OBRIGA a usar os algoritmos da STL sempre que
** apropriado. Por isso usamos std::find em vez de escrever um for à mão.
*/
#include <algorithm>
#include <stdexcept>

/*
** TEMPLATE DA FUNÇÃO
**
** template <typename T>
**   -> T é um "tipo genérico". O compilador substitui T pelo tipo real
**      do contentor no momento da chamada. Ex.: easyfind(vec, 20) com
**      vec do tipo std::vector<int>  =>  T = std::vector<int>.
**
** typename T::iterator
**   -> Tipo de retorno: o iterador do contentor T.
**   -> A palavra 'typename' é obrigatória porque T::iterator é um "nome
**      dependente" (depende de T, que ainda não se conhece). Sem 'typename'
**      o compilador não sabe se T::iterator é um tipo ou um valor.
**
** (T &container, int value)
**   -> container: passado por REFERÊNCIA (sem cópia, e o iterador devolvido
**      aponta para o contentor ORIGINAL, não para uma cópia que morreria
**      no fim da função).
**   -> value: o inteiro a procurar (o subject diz que o 2.º parâmetro é int).
**
** Como as funções template podem ficar no header (exceção à regra de "sem
** implementações em headers"), a definição completa está aqui.
*/
template <typename T>
typename T::iterator easyfind(T &container, int value) {

    /*
    ** std::find(first, last, value)
    **   -> Percorre o intervalo [first, last) e devolve um iterador para o
    **      PRIMEIRO elemento igual a 'value'.
    **   -> Se não encontrar nada, devolve 'last' (neste caso container.end()).
    **   -> Funciona com qualquer contentor sequencial, porque só precisa de
    **      iteradores (vector, list, deque...).
    */
    typename T::iterator it = std::find(container.begin(), container.end(), value);

    /*
    ** TRATAMENTO DO "NÃO ENCONTRADO"
    ** end() não aponta para um elemento válido: é a posição "um depois do
    ** último". Se 'it' for igual a end(), significa que o valor não existe.
    ** O subject permite lançar exceção OU devolver um valor de erro.
    ** Optámos pela exceção, que é a forma mais limpa de sinalizar o erro
    ** (e não há nenhum valor de iterador "inválido" universal para devolver).
    */
    if (it == container.end()) {
        throw std::runtime_error("Elemento não encontrado no contentor");
    }

    /*
    ** Encontrado: devolvemos o iterador. Quem chama pode:
    **   - ler o valor          : *it
    **   - modificar o valor    : *it = 42;
    **   - calcular a posição   : std::distance(container.begin(), it)
    */
    return it;
}

#endif /* EASYFIND_HPP */
