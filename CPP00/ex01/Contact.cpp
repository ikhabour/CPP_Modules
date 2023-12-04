#include "Contact.hpp"

void    Contact::assign(std::string nickname, std::string first_name, std::string last_name, std::string phone_number, std::string dsecret)
{
    nick = nickname;
    fname = first_name;
    lname = last_name;
    phone = phone_number;
    secret = dsecret;
}

std::string Contact::get_nick()
{
    return (Contact::nick);
}

void    Contact::display()
{
    if (fname.length() >= 10)
    {
        std::string truncfname;
        truncfname = fname.substr(0, 10);
        truncfname[9] = '.';
        std::cout<<std::setw(10)<<truncfname<<"|";
    }
    else
        std::cout<<std::setw(10)<<fname<<"|";
    if (lname.length() >= 10)
    {
        std::string trunclname;
        trunclname = lname.substr(0, 10);
        trunclname[9] = '.';
        std::cout<<std::setw(10)<<trunclname<<"|";
    }
    else
        std::cout<<std::setw(10)<<lname<<"|";
    if (nick.length() >= 10)
    {
        std::string truncnick;
        truncnick = nick.substr(0, 10);
        truncnick[9] = '.';
        std::cout<<std::setw(10)<<truncnick<<"|"<<std::endl;
    }
    else
        std::cout<<std::setw(10)<<nick<<"|"<<std::endl;
}


void    Contact::info()
{
    if (nick.empty())
    {
        std::cout<<"Contact has no information yet."<<std::endl;
        return ;
    }
    std::cout<<"Contact's Nickname : "<<nick<<std::endl;
    std::cout<<"Contact's First name : "<<fname<<std::endl;
    std::cout<<"Contact's Last name : "<<lname<<std::endl;
    std::cout<<"Contact's Phone number : "<<phone<<std::endl;
    std::cout<<"Contact's Darkest secret : "<<secret<<std::endl;
}