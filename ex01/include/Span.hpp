#include <exception>
#include <vector>
#include <algorithm>
#include <iostream>

class Span {
    private:
        std::vector<int> _storage;
        unsigned int _size;
    public:
        Span(unsigned int n);
        Span(const Span &src);
        ~Span();
        Span &operator=(const Span &src);

        void addNumber(int n);
        void addMultiNumbers(unsigned int n);
        int longestSpan() const;
        int shortestSpan() const;

        void printStorage();

        class MoreThanMaxSize : public std::exception {
            public:
                const char *what() const throw();
        };
};