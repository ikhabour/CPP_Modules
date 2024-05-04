#pragma once

#include "Array.hpp"

template <typename T>
Array<T>::Array()
{
    this->arr = NULL;
    this->arr_size = 0;
}

template <typename T>
Array<T>::Array(size_t n)
{
    this->arr_size = n;
    this->arr = new T[n]();
}

template <typename T>
Array<T>::Array(const Array& other) : arr(NULL)
{
    *this = other;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
    if (this != &other)
    {
        if (this->arr)
            delete[] this->arr;
        this->arr_size = other.arr_size;
        this->arr = new T[arr_size]();
        for (size_t i = 0; i < this->arr_size; i++)
            this->arr[i] = other.arr[i];
    }
    return *this;
}


template <typename T>
T& Array<T>::operator[](int index) const
{
    if (index >= (int)this->arr_size || index < 0)
        throw std::runtime_error("index out of bounds");
    return (this->arr[index]);
}

template <typename T>
size_t Array<T>::size() const
{
    return (this->arr_size);
}

template <typename T>
Array<T>::~Array()
{
    if (this->arr)
        delete[] this->arr;
}