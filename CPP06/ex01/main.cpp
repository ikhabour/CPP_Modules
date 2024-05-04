#include "Serializer.hpp"

void    print_d(Data* ptr)
{
    std::cout<<"Name : "<<ptr->name<<std::endl;
    std::cout<<"Age : "<<ptr->age<<std::endl;
    std::cout<<"Height : "<<ptr->height<<std::endl;
}

int main()
{
    Data ptr;
    uintptr_t num = 0;

    ptr.age = 10;
    ptr.name = "something";
    ptr.height = 1.78;
    std::cout<<"data : "<<std::endl;
    print_d(&ptr);
    num = Serializer::serialize(&ptr);
    std::cout<<"Value after conversion : "<<num<<std::endl;
    Data *ptr1;

    ptr1 = Serializer::deserialize(num);
    std::cout<<std::endl;
    print_d(ptr1);
    std::cout<<"Address of ptr : "<<&ptr<<std::endl;
    std::cout<<"Address of ptr1 : "<<ptr1<<std::endl;

}