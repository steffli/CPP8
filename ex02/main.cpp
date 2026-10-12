#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <vector>
#include <string>

int main()
{
    std::cout << "=== Subject test (MutantStack) ===" << std::endl;
    {
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        std::cout << mstack.top() << std::endl;
        mstack.pop();
        std::cout << mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        //[...]
        mstack.push(0);
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::stack<int> s(mstack);
    }

    std::cout << "=== Same test with std::list (output must match) ===" << std::endl;
    {
        std::list<int> lst;
        lst.push_back(5);
        lst.push_back(17);
        std::cout << lst.back() << std::endl;
        lst.pop_back();
        std::cout << lst.size() << std::endl;
        lst.push_back(3);
        lst.push_back(5);
        lst.push_back(737);
        //[...]
        lst.push_back(0);
        std::list<int>::iterator it = lst.begin();
        std::list<int>::iterator ite = lst.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::list<int> l(lst);
    }

    std::cout << "=== Reverse iteration ===" << std::endl;
    {
        MutantStack<int> mstack;
        for (int i = 1; i <= 5; i++)
            mstack.push(i);
        for (MutantStack<int>::reverse_iterator it = mstack.rbegin(); it != mstack.rend(); ++it)
            std::cout << *it << " ";
        std::cout << std::endl;
    }

    std::cout << "=== Const iteration + copy is independent ===" << std::endl;
    {
        MutantStack<std::string> a;
        a.push("hello");
        a.push("mutant");
        MutantStack<std::string> b(a);
        b.push("stack");
        const MutantStack<std::string> &cref = b;
        for (MutantStack<std::string>::const_iterator it = cref.begin(); it != cref.end(); ++it)
            std::cout << *it << " ";
        std::cout << std::endl;
        std::cout << "a.size() = " << a.size() << ", b.size() = " << b.size() << std::endl;
        a = b;
        std::cout << "after a = b, a.top() = " << a.top() << std::endl;
    }

    std::cout << "=== Other underlying container (std::vector) ===" << std::endl;
    {
        MutantStack<int, std::vector<int> > vstack;
        vstack.push(42);
        vstack.push(21);
        for (MutantStack<int, std::vector<int> >::iterator it = vstack.begin(); it != vstack.end(); ++it)
            std::cout << *it << " ";
        std::cout << std::endl;
    }

    std::cout << "=== Empty stack ===" << std::endl;
    {
        MutantStack<int> empty;
        std::cout << "begin == end: " << (empty.begin() == empty.end() ? "yes" : "no") << std::endl;
    }
    return 0;
}
