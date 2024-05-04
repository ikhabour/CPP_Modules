#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include <exception>
#include <limits.h>
#include <cstdlib>
#include <ctime>

class Span
{
    private: 
        std::vector<int> vec;
        unsigned int max_num;
    public:
        Span();
        Span(unsigned int N);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();

        void    addNumber(int number);
        int shortestSpan();
        int longestSpan();
        void    Fill_vector(int min, int max);
        void    print_elements();


        class VectorFullException : public std::exception
        {
            public:
                const char *what() throw()
                {
                    return ("Vector is full");
                }
        };

        class NoSpanAvailableException : public std::exception
        {
            public:
                const char *what() throw()
                {
                    return ("Vector is either empty or contains only one element.");
                }
        };
};