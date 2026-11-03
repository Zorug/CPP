#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main() {
    // 📦 1. Teste com std::vector
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);

    try {
        // Cenário de sucesso: elemento existe
        std::vector<int>::iterator it = easyfind(vec, 20);
        std::cout << "✅ Encontrado no vector: " << *it << std::endl;
    } catch (const std::exception &e) {
        std::cout << "❌ Erro: " << e.what() << std::endl;
    }

    try {
        // Cenário de erro: elemento não existe (deve lançar exceção)
        easyfind(vec, 99);
    } catch (const std::exception &e) {
        std::cout << "⚠️ Exceção capturada com sucesso: " << e.what() << std::endl;
    }

    // 🔗 2. Teste com std::list
    std::list<int> lst;
    lst.push_back(100);
    lst.push_back(200);

    try {
        std::list<int>::iterator it = easyfind(lst, 100);
        std::cout << "✅ Encontrado na list: " << *it << std::endl;
    } catch (const std::exception &e) {
        std::cout << "❌ Erro: " << e.what() << std::endl;
    }

    return 0;
}