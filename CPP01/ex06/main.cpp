#include "Harl.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr<<"Error"<<std::endl;
        return 1;
    }
    Harl obj;
    obj.complain(argv[1]);
}