#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain
{
private:
    std::string ideas[100];

public:
    // Orthodox Canonical Form
    Brain();
    Brain(const Brain& other);
    Brain& operator=(const Brain& other);
    ~Brain();

    // Additional Methods to manage ideas
    void setIdea(int index, const std::string& idea);
    std::string getIdea(int index) const;
};

#endif