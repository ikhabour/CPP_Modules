#pragma once


#include <iostream>


typedef struct s_Data
{
    std::string name;
    int age;
    float height;
} Data;

typedef unsigned long uintptr_t;

class Serializer
{
    private:
        Serializer();
        Serializer(const Serializer& other);
        Serializer& operator=(const Serializer& other);
        ~Serializer();
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};