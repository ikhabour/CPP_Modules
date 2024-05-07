#include "RPN.hpp"


int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr<<"Usage : ./RPN \"Expression\""<<std::endl;
        return 1;
    }
    try
    {
        RPN a(argv[1]);
    }
    catch (std::exception& e)
    {
        std::cerr<<e.what()<<std::endl;
    }
    return 0;
}