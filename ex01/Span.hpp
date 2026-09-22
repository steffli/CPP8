#ifndef SPAN_HPP
#define SPAN_HPP
#include <string>
#include <iostream>
#include <vector>

class Span{
    private:
        unsigned int N;
        std::vector<int> vec;
    
    public:
        Span();
        Span(unsigned int N);
        Span(const Span &copy);
        Span &operator=(const Span &copy);
        ~Span();

        void addNumber(int n);

        class OutofBounds : public std::exception{
            public:
                virtual const char* what() const throw();
        };
};

#endif