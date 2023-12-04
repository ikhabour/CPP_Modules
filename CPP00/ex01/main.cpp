#include "PhoneBook.hpp"


int main()
{
    std::string cmd;
    PhoneBook pbook;
    int i = 0;

    pbook.welcome();
    while (1)
    {
        if (i == 8)
            i = 0;
        std::cout<<"PHONEBOOK$> ";
        std::getline(std::cin, cmd);
        if (std::cin.eof())
            _exit(1);
        if (cmd == "ADD")
        {
            pbook.add_contact(i);
            i++;
        }
        else if (cmd == "SEARCH")
        {
            std::cout<<std::endl;
            pbook.search();
            std::cout<<std::endl;
        }
        else if (cmd == "EXIT")
        {
            _exit(0);
        }
        else if (!cmd.empty())
            std::cout<<"Unknown command."<<std::endl;
    }
}