#include "Iter.hpp"

template <typename T>
void    print(T& a)
{
    std::cout<<"Element : "<<a<<std::endl;
}

template <typename T>
void    add_one(T& n)
{
    n++;
}

int main()
{
    int arr[3] = {1, 2, 3};
    ::Iter(arr, 3, print);
    ::Iter(arr, 3, add_one);
    std::cout<<"\nAfter\n"<<std::endl;;
    ::Iter(arr, 3, print);
    return 0;
}