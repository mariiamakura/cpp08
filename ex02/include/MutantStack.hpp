#pragma once

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
    public:
        MutantStack();
        MutantStack(const MutantStack &src);
        MutantStack &operator=(const MutantStack &src);
        ~MutantStack();

        typedef typename std::stack<T>::container_type::iterator iterator;
        iterator begin();
        iterator end();
};

template <typename T>
MutantStack<T>::MutantStack() {
    std::cout << "Mutant constructor" << std::endl;
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &src) {
    *this = src;
    std::cout << "Mutant COPY constructor" << std::endl;
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &src) {
    std::cout << "Mutant COPY OPERATOR= constructor" << std::endl;
    std::stack<T>::operator=(src);
    return (*this);
}

template <typename T>
MutantStack<T>::~MutantStack() {
    std::cout << "Mutant deconstructor" << std::endl;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
    return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
    return (this->c.end());
}