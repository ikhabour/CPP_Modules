#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <iomanip>
#include <unistd.h>
#include <limits>
#include <cstdlib>

class   Contact
{
    private :
        std::string nick;
        std::string fname;
        std::string lname;
        std::string phone;
        std::string secret;
    public :
        void    assign(std::string nickname, std::string first_name, std::string last_name, std::string phone_number, std::string dsecret);
        void    display();
        void    info();
        std::string get_nick();
};

#endif