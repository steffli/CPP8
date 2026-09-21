#ifndef EASYFIND_TPP
#define EASYFIND_TPP
#include "easyfind.hpp"

const char* NotFound::what() const throw(){
    return "Value not found";
}

template <typename T>
typename T::iterator easyfind(T &container, int occ){
    typename T::iterator i = container.begin();
    for (; i != container.end(); ++i)
    {
        if (*i == occ)
            return i;
    }
    throw NotFound();
}


#endif