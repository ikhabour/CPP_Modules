#pragma once


#include <iostream>

template <typename T>
void easyfind(T &container, int value)
{
    for (typename T::iterator i = container.begin(); i != container.end(); i++)
        if (*i == value)
        {
            std::cout<<"Value found"<<std::endl;
            return ;
        }
    std::cout<<"Value not found"<<std::endl;
}