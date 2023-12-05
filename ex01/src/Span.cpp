#include "../include/Span.hpp"

Span::Span(unsigned int n) : _storage(0), _size(n) {}

Span::Span(const Span &src) {
    *this = src;
}

Span &Span::operator=(const Span &src) {
    if (this != &src) {
        this->_size = src._size;
        this->_storage = src._storage;
    }
    return (*this);
}

Span::~Span() {}

void Span::addNumber(int n) {
    if (this->_storage.size() == this->_size)
        throw Span::MoreThanMaxSize();
    this->_storage.push_back(n);
}

void Span::addMultiNumbers(unsigned int n) {
    srand(time(NULL));
    try {
        for (unsigned int i = 0; i < n; i++) {
            this->addNumber(rand());
        }
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}

void Span::printStorage() {
    std::vector<int>::iterator it;

    for (it = this->_storage.begin(); it != this->_storage.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

const char *Span::MoreThanMaxSize::what() const throw() {
    return ("More than max size of storage");
}

int Span::longestSpan() const {
    if (this->_storage.size() < 2)
        throw std::out_of_range("Not enough elements");
    int min = *std::min_element(this->_storage.begin(), this->_storage.end());
    int max = *std::max_element(this->_storage.begin(), this->_storage.end());

    return (abs(max - min));
}

int Span::shortestSpan() const {
    if (this->_storage.size() < 2)
        throw std::out_of_range("Not enough elements");

    std::vector<int> sorted = this->_storage;
    std::sort(sorted.begin(), sorted.end());
    int min = abs(sorted.at(1) - sorted.at(0));

    std::vector<int>::iterator it;
    for (it = sorted.begin(); it != sorted.end(); it++) {
        if (abs(*(it + 1) - *it) < min)
            min = abs(*(it + 1) - *it);
    }
    return (min);
}

