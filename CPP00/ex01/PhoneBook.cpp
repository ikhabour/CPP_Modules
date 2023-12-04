#include "PhoneBook.hpp"

void    PhoneBook::welcome()
{
    std::cout<<"\nWelcome to your phonebook!\n"<<std::endl;
    std::cout<<"------------------> USAGE <-----------------------"<<std::endl;
    std::cout<<" ADD : add a contact to your phonebook."<<std::endl;
    std::cout<<" SEARCH : to search for a contact on your phonebook."<<std::endl;
    std::cout<<" EXIT : to exit your phonebook."<<std::endl;
    std::cout<<"--------------------------------------------------"<<std::endl;
}

std::string replace_tab(std::string str)
{
    size_t index = 0;
    while (str[index])
    {
        if (str[index] == '\t')
            str.replace(index, 1, "    ");
        index++;
    }
    return (str);
}

int contains_nonprint(std::string str)
{
    for (int i = 0; str[i]; i++)
    {
        if (!std::isprint(str[i]))
        {
            if (std::isspace(str[i]))
                continue;
            return (0);
        }
    }
    return (1);
}

int isonlywhitespace(std::string str)
{
    for (int i = 0; str[i]; i++)
    {
        if (!std::isspace(str[i]))
            return (0);
    }
    return (1);
}

void    PhoneBook::add_contact(int i)
{
    std::string nickname;
    std::string first_name;
    std::string last_name;
    std::string phone_number;
    std::string secret;

    while (nickname.empty())
    {
        std::cout<<"Enter contact's nickname :"<<std::endl;
        std::getline(std::cin, nickname);
        if (std::cin.eof())
            _exit(0);
        if (isonlywhitespace(nickname))
        {
            std::cout<<"Error"<<std::endl;
            nickname.clear();
            continue;
        }
        if (!contains_nonprint(nickname))
        {
            std::cout<<"Error"<<std::endl;
            nickname.clear();
            continue;
        }
        nickname = replace_tab(nickname);
    }
    while (first_name.empty())
    {
        std::cout<<"Enter contact's First name :"<<std::endl;
        std::getline(std::cin, first_name);
        if (std::cin.eof())
            _exit(0);
        if (isonlywhitespace(first_name))
        {
            std::cout<<"Error"<<std::endl;
            first_name.clear();
            continue;
        }
        if (!contains_nonprint(first_name))
        {
            std::cout<<"Error"<<std::endl;
            first_name.clear();
            continue;
        }
        first_name = replace_tab(first_name);
    }
    while (last_name.empty())
    {
        std::cout<<"Enter contact's Last name :"<<std::endl;
        std::getline(std::cin, last_name);
        if (std::cin.eof())
            _exit(0);
        if (isonlywhitespace(last_name))
        {
            std::cout<<"Error"<<std::endl;
            last_name.clear();
            continue;
        }
        if (!contains_nonprint(last_name))
        {
            std::cout<<"Error"<<std::endl;
            last_name.clear();
            continue;
        }
        last_name = replace_tab(last_name);
    }
    while (phone_number.empty())
    {
        std::cout<<"Enter contact's Phone number :"<<std::endl;
        std::getline(std::cin, phone_number);
        if (std::cin.eof())
            _exit(0);
        for (int x = 0; phone_number[x]; x++)
        {
            if (!std::isdigit(phone_number[x]))
            {
                std::cout<<"Error"<<std::endl;
                phone_number.clear();
                break;
            }
        }
        if (!contains_nonprint(phone_number))
        {
            std::cout<<"Error"<<std::endl;
            phone_number.clear();
            continue;
        }
        phone_number = replace_tab(phone_number);
    }
    while (secret.empty())
    {
        std::cout<<"Enter contact's Darkest secret :"<<std::endl;
        std::getline(std::cin, secret);
        if (std::cin.eof())
            _exit(0);
        if (isonlywhitespace(secret))
        {
            std::cout<<"Error"<<std::endl;
            secret.clear();
            continue;
        }
        if (!contains_nonprint(secret))
        {
            std::cout<<"Error"<<std::endl;
            secret.clear();
            continue;
        }
        secret = replace_tab(secret);
    }
    contacts[i].assign(nickname, first_name, last_name, phone_number, secret);
    std::cout<<"Contact has been saved!"<<std::endl;
}

int count_contacts(Contact *contacts)
{
    int cts = 0;
    for (int i = 0; i < 8; i++)
    {
        if (!contacts[i].get_nick().empty())
            cts++;
    }
    return cts;
}

void    PhoneBook::search()
{
    int i = 0;
    std::string entered_index;
    int available_contacts = count_contacts(contacts);
    int index;
    std::cout<<std::setw(10)<<"Index"<<"|"
    <<std::setw(10)<<"First Name"<<"|"
    <<std::setw(10)<<"Last Name"<<"|"
    <<std::setw(10)<<"Nickname"<<"|"<<std::endl;
    while (i < available_contacts)
    {
        std::cout<<std::setw(10)<<i + 1<<"|";
        contacts[i].display();
        i++;
    }
    while (entered_index.empty())
    {
        std::cout<<"\nEnter the index of the contact :"<<std::endl;
        std::getline(std::cin, entered_index);
        if (std::cin.eof())
            _exit(0);
        for (int x = 0; entered_index[x]; x++)
        {
            if (entered_index[x] == ' ' || !(entered_index[x] >= '0' && entered_index[x] <= '9'))
            {
                std::cout<<"Invalid Index."<<std::endl;
                return ;
            }
        }
    }
    index = std::atoi(entered_index.data());
    if (index < 1 || index > 8)
    {
        std::cout<<"\nInvalid Index : out of range."<<std::endl;    
        return ;
    }
    index--;
    contacts[index].info();
}
