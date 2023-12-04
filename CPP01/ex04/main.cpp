#include "Sed.hpp"


int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout<<"Error"<<std::endl;
        return 1;
    }
    replace(argv[1], argv[2], argv[3]);
}