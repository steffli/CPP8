#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
#include <stack>
#include <iostream>
#include <string>

template <typename T>
class MutantStack : public std::stack<T>{
    private:
        std::stack<int> mstack;
        unsigned int N;
    public:
        MutantStack();
        MutantStack(const MutantStack &copy);
        MutantStack &operator(const MutantStack &copy);
        ~MutantStack();


};

#endif