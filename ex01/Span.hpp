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
        ~Span();
};

#endif