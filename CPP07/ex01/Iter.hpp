#pragma once

#include <iostream>

template <typename T, typename F>
void    Iter(T *array, size_t size, F func)
{
    for (size_t i = 0; i < size; i++)
        func(array[i]);
}