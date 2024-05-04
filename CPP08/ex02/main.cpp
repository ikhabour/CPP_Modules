#include "MutantStack.hpp"

int main()
{
    MutantStack<int> obj;

    obj.push(1);
    obj.push(2);
    obj.push(3);

    for (MutantStack<int>::iterator it = obj.begin(); it != obj.end(); it++)
        std::cout<<*it<<std::endl;
    
}