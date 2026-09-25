#include "Span.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
    std::cout << "--- subject example ---" << std::endl;
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl; // 2
    std::cout << sp.longestSpan() << std::endl;  // 14

    std::cout << "--- adding to a full span ---" << std::endl;
    try {
        sp.addNumber(42);
    } catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "--- empty span ---" << std::endl;
    Span empty(10);
    try {
        empty.shortestSpan();
    } catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "--- one number ---" << std::endl;
    Span one(10);
    one.addNumber(5);
    try {
        one.longestSpan();
    } catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "--- duplicates ---" << std::endl;
    Span dup(3);
    dup.addNumber(7);
    dup.addNumber(1);
    dup.addNumber(7);
    std::cout << dup.shortestSpan() << std::endl; // 0
    std::cout << dup.longestSpan() << std::endl;  // 6

    std::cout << "--- negative numbers ---" << std::endl;
    Span neg(4);
    neg.addNumber(-10);
    neg.addNumber(5);
    neg.addNumber(-3);
    neg.addNumber(20);
    std::cout << neg.shortestSpan() << std::endl; // 7
    std::cout << neg.longestSpan() << std::endl;  // 30

    std::cout << "--- copy is independent ---" << std::endl;
    Span a(3);
    a.addNumber(1);
    a.addNumber(10);
    Span b(a);
    b.addNumber(11);
    std::cout << a.shortestSpan() << std::endl; // 9
    std::cout << b.shortestSpan() << std::endl; // 1

    std::cout << "--- 10000 numbers ---" << std::endl;
    std::srand(std::time(NULL));
    Span big(10000);
    for (int i = 0; i < 10000; i++)
        big.addNumber(std::rand());
    std::cout << big.shortestSpan() << std::endl;
    std::cout << big.longestSpan() << std::endl;

    return 0;
}
