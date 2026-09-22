#include "Span.hpp"

Span::Span() : N(0), vec(NULL){};

Span::Span(unsigned int N) : N(N), vec(vec[N]){};

Span::Span(const Span &copy) : N(copy.N), vec(copy.vec){}

Span& Span::operator=(const Span &copy){
    if (this != &copy)
    {
        this->N = copy.N;
        this->vec = copy.vec;
    }
    return *this;
}
Span::~Span(){};

void Span::addNumber(int n){
    if (this->vec.size() >= this->N)
        throw OutofBounds();
    vec.push_back(n);
}

