#include "Harl.hpp"

void    Harl::debug()
{
    std::cout<<"[ DEBUG ]"<<std::endl;
    std::cout<<"I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"<<std::endl;
}

void    Harl::info()
{
    std::cout<<"[ INFO ]"<<std::endl;
    std::cout<<"I cannot believe adding extra bacon costs more money.\nYou didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!"<<std::endl;
}

void    Harl::warning()
{
    std::cout<<"[ WARNING ]"<<std::endl;
    std::cout<<"I think I deserve to have some extra bacon for free.\nI've been coming for years whereas you started working here since last month."<<std::endl;
}

void    Harl::error()
{
    std::cout<<"[ ERROR ]"<<std::endl;
    std::cout<<"This is unacceptable! I want to speak to the manager now."<<std::endl;
}

void    Harl::complain(std::string level)
{
    void (Harl::*funcptr[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int i = 0;
    while (i < 4 && levels[i].compare(level))
        i++;
    switch (i)
    {
        case 0:
            for (int j = 0; j < 4; j++)
            {
                (this->*funcptr[j])();
                std::cout<<std::endl;
            }
            break;
        case 1:
            for (int j = 1; j < 4; j++)
            {
                (this->*funcptr[j])();
                std::cout<<std::endl;
            }
            break;
        case 2:
            for (int j = 2; j < 4; j++)
            {
                (this->*funcptr[j])();
                std::cout<<std::endl;
            }
            break;
        case 3:
            (this->*funcptr[i])();
            std::cout<<std::endl;
            break;
        default:
            std::cout<<"This level is not found."<<std::endl;
    }
}