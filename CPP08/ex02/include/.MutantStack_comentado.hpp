/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 14:13:58 by cgross-s          #+#    #+#             */
/*   Updated: 2026/11/10 14:48:45 by cgross-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ex02 - Mutated abomination
**
** std::stack é um "adaptador de contentor": por baixo guarda os dados num
** outro contentor (por defeito, std::deque) mas só expõe push/pop/top/size/
** empty. Não tem begin()/end(), logo não é iterável.
**
** TRUQUE DO EXERCÍCIO: o contentor interno é um membro PROTEGIDO chamado
** 'c'. Se herdarmos de std::stack, temos acesso a 'c' e podemos expor os
** iteradores dele. Ficamos com uma stack normal + begin()/end().
*/

/* INCLUDE GUARDS: evitam a dupla inclusão. */
#ifndef MUTATEDSTACK_HPP
#define MUTATEDSTACK_HPP

/* <stack> fornece std::stack (e, indiretamente, o contentor por defeito). */
#include <stack>

/*
** HERANÇA PÚBLICA de std::stack<T>
**   -> MutatedStack herda TODAS as funções (push, pop, top, size, empty...),
**      por isso cumprimos o "offer all its member functions" do subject
**      sem reescrever nada.
**   -> Por ser pública, um MutatedStack "é uma" std::stack, e pode ser
**      convertido/copiado para uma std::stack (ver o teste do main).
*/
template <typename T>
class MutatedStack : public std::stack<T> {
public:
    /* ---------------------------------------------------------------- */
    /*  ORTHODOX CANONICAL FORM                                          */
    /*  Como é um template, tudo fica no header (permitido).             */
    /* ---------------------------------------------------------------- */

    /* Construtor por defeito: constrói a stack base vazia. */
    MutatedStack() : std::stack<T>() {}

    /* Construtor de cópia: passa 'other' à base, que copia o contentor
    ** interno 'c' (cópia profunda feita pelo próprio contentor). */
    MutatedStack(const MutatedStack &other) : std::stack<T>(other) {}

    /*
    ** Operador de atribuição: protege contra auto-atribuição e delega
    ** a cópia na versão da classe base.
    ** Escrevemos std::stack<T>::operator=(other) explicitamente para
    ** chamar o operador da BASE (senão haveria recursão infinita).
    */
    MutatedStack &operator=(const MutatedStack &other) {
        if (this != &other) {
            std::stack<T>::operator=(other);
        }
        return *this;
    }

    /*
    ** Destrutor virtual: boa prática em classes pensadas para herança.
    ** (Nota: std::stack tem destrutor não virtual, por isso aqui é
    ** inofensivo mas não essencial.)
    */
    virtual ~MutatedStack() {}

    /* ---------------------------------------------------------------- */
    /*  DEFINIÇÃO DOS ITERADORES                                         */
    /* ---------------------------------------------------------------- */

    /*
    ** std::stack<T>::container_type é o tipo do contentor interno
    ** (por defeito std::deque<T>). Pegamos nos iteradores desse tipo e
    ** damos-lhes nomes iguais aos dos contentores standard (iterator /
    ** const_iterator), para o MutatedStack se usar como um vector ou list:
    **     MutatedStack<int>::iterator it = mstack.begin();
    **
    ** 'typename' é obrigatório: container_type::iterator depende de T,
    ** logo o compilador precisa de saber que isto é um TIPO.
    */
    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;

    /* ---------------------------------------------------------------- */
    /*  MÉTODOS DE NAVEGAÇÃO                                             */
    /* ---------------------------------------------------------------- */

    /*
    ** 'c' é o membro protegido de std::stack que guarda os dados.
    ** Usamos 'this->c' (e não só 'c') porque a classe base é dependente
    ** do template: sem 'this->' o compilador não procura 'c' na base e
    ** dá erro de "nome não declarado".
    **
    ** begin() -> primeiro elemento (o FUNDO da stack)
    ** end()   -> uma posição depois do último (o topo + 1)
    */
    iterator begin() { return this->c.begin(); }
    iterator end() { return this->c.end(); }

    /*
    ** Versões const: permitem iterar sobre uma MutatedStack constante
    ** (por exemplo, passada como 'const MutatedStack &'), devolvendo
    ** const_iterator para não deixar alterar os elementos.
    */
    const_iterator begin() const { return this->c.begin(); }
    const_iterator end() const { return this->c.end(); }
};

#endif
