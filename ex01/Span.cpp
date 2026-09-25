#include "Span.hpp"

Span::Span() : N(0){};

Span::Span(unsigned int N) : N(N){};

Span::Span(const Span &copy) : N(copy.N), vec(copy.vec){}

Span& Span::operator=(const Span &copy){
    if (this != &copy)
    {
        N = copy.N;
        vec = copy.vec;
    }
    return *this;
}
Span::~Span(){};

void Span::addNumber(int n){
    if (vec.size() >= N)
        throw OutofBounds();
    vec.push_back(n);
}

int Span::shortestSpan(){
    if (N <= 1)
        throw NotEnoughNumbers();
    int min = abs(vec[1] - vec[0]);
    for (int i = 2; i < vec.size(); ++i)
        for (int j = i + 1; j < vec.size(); ++j)
            min = std::min(min, vec[j] - vec[i]);
    return min;
}
int Span::longestSpan(){
    if (N <= 1)
        throw NotEnoughNumbers();
    return (*std::max_element(vec.begin(), vec.end()) - *std::max_element(vec.begin(), vec.end()));
}

const char* Span::NotEnoughNumbers::what() const throw(){
    return "Not enough numbers in vector.";
}

const char* Span::OutofBounds::what() const throw(){
    return "Span is full.";
} 