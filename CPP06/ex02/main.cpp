#include "file.hpp"

Base* generate()
{
    std::srand(std::time(NULL));
    int num = rand() % 3;
    if (num == 0)
        return new A;
    else if (num == 1)
        return new B;
    else
        return new C;
}

void    Identify(Base* p)
{
    if (dynamic_cast<A*>(p))
    {
        std::cout<<"Ptr : A"<<std::endl;
        return;
    }
    else if (dynamic_cast<B*>(p))
    {
        std::cout<<"Ptr : B"<<std::endl;
        return;
    }
    else if (dynamic_cast<C*>(p))
    {
        std::cout<<"Ptr : C"<<std::endl;
        return;
    }

}

void    Identify(Base& p)
{
    try
    {
        dynamic_cast<A&>(p);
        std::cout<<"Ref : A"<<std::endl;
    }
    catch(std::exception &e) {}
    try
    {
        dynamic_cast<B&>(p);
        std::cout<<"Ref : B"<<std::endl;
    }
    catch(std::exception &e) {}
    try
    {
        dynamic_cast<C&>(p);
        std::cout<<"Ref : C"<<std::endl;
    }
    catch(std::exception &e) {}
}


int main()
{
    Base* p = generate();
    Base& a = *p;
    Identify(p);
    Identify(a);
}