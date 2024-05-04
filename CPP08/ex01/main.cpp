#include "Span.hpp"


int main()
{
    Span sp = Span(5);
    sp.Fill_vector(1, 100000);
    sp.print_elements();

    std::cout <<"shortest span : "<< sp.shortestSpan() << std::endl;
    std::cout <<"longest Span : "<< sp.longestSpan() << std::endl;
    return 0;
}