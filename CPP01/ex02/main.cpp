#include <iostream>


int main()
{
    std::string var = "HI THIS IS BRAIN";
    std::string *stringPTR = &var;
    std::string &stringREF = var;

    std::cout<<"The memory address of the string variable : "<<&var<<std::endl;
    std::cout<<"The memory address held by stringPTR : "<<stringPTR<<std::endl;
    std::cout<<"The memory address held by stringREF : "<<&stringPTR<<std::endl;

    std::cout<<"\nThe value of the string variable : "<<var<<std::endl;
    std::cout<<"The value pointed to by stringPTR : "<<*stringPTR<<std::endl;
    std::cout<<"The value pointed to by stringREF : "<<stringREF<<std::endl;

}