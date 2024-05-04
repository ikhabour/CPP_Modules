#pragma once
#include <exception>

template <typename T>
class Array
{
    private:
        T* arr;
        size_t arr_size;

    public:
        Array();
        Array(size_t n);
        Array(const Array& other);
        Array& operator=(const Array& other);
        T& operator[](int index) const;
        ~Array();

        size_t size() const;
};

#include "Array.tpp"
