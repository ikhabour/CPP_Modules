#include "Bureaucrat.hpp"

int main( void )
{
    Bureaucrat b("youssef", 35);
    Form f("form1", 50, 30);

    try
    {
        b.signForm(f);
    }
    catch(const std::exception &e)
    {
        std::cerr<<e.what()<<std::endl;
    }
    return 0;
}