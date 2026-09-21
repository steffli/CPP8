#include "easyfind.hpp"
#include <vector>
#include <list>
#include <iostream>

int main()
{
    std::vector<int> vec;
    for (int i = 0; i < 5; i++)
        vec.push_back(i * 2); // 0 2 4 6 8

    std::cout << "-- vector --" << std::endl;
    try
    {
        std::vector<int>::iterator it = easyfind(vec, 6);
        std::cout << "found: " << *it << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "exception: " << e.what() << std::endl;
    }

    try
    {
        std::vector<int>::iterator it = easyfind(vec, 7);
        std::cout << "found: " << *it << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "exception: " << e.what() << std::endl;
    }

    std::list<int> lst;
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);

    std::cout << "-- list --" << std::endl;
    try
    {
        std::list<int>::iterator it = easyfind(lst, 20);
        std::cout << "found: " << *it << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "exception: " << e.what() << std::endl;
    }

    try
    {
        std::list<int>::iterator it = easyfind(lst, 99);
        std::cout << "found: " << *it << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "exception: " << e.what() << std::endl;
    }

    return 0;
}
