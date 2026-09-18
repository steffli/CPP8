#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <iostream>
#include <exception>
#include <string>

class NotFound : public std::exception{
    public:
        virtual const char *what() const throw();
};

template <typename T>
T easyfind(T conainer, unsigned int occ){
    for (unsigned int i; i < container.size(); i++)
    {
        if (container[i] == occ)
            return occ;
        else 
            return -1;
    }
}

#include "easyfind.tpp"
#endif