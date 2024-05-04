#include "Span.hpp"


Span::Span() {}

Span::Span(unsigned int N)
{
    this->max_num = N;
}

Span::Span(const Span& other)
{
    *this = other;
}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        this->vec = other.vec;
        this->max_num = other.max_num;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int number)
{
    if (vec.size() >= this->max_num)
        throw Span::VectorFullException();
    vec.push_back(number);
}

int Span::longestSpan()
{
    if (this->vec.size() <= 1)
        throw Span::NoSpanAvailableException();
    int max = *std::max_element(vec.begin(), vec.end());
    int min = *std::min_element(vec.begin(), vec.end());
    return (max - min);
}

int Span::shortestSpan()
{
    if (this->vec.size() <= 1)
        throw Span::NoSpanAvailableException();
    int min = INT_MAX;
    std::vector<int> copy = vec;
    std::sort(copy.begin(), copy.end());
    for (size_t i = 1; i < copy.size(); i++)
    {
        int distance = copy[i] - copy[i - 1];
        min = std::min(min, distance);
    }
    return min;
}

void    Span::Fill_vector(int min, int max)
{
    if (this->vec.size() >= this->max_num)
        throw Span::VectorFullException();
    std::srand(std::time(0));
    int num = 0;
    for (size_t i = 0; i < this->max_num; i++)
    {
        num = min + std::rand() % (max - min + 1);
        this->vec.push_back(num);
    }
}

void    Span::print_elements()
{
    for (size_t i = 0; i < this->max_num; i++)
        std::cout<<vec[i]<<std::endl;
}