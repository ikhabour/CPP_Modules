#include "BitcoinExchange.hpp"



int main(int argc, char **argv)
{
    if (argc == 2)
        BitcoinExchange btc(argv[1]);
    else
    {
        std::cerr<<"Usage : ./btc filename"<<std::endl;
        return 1;
    }
}