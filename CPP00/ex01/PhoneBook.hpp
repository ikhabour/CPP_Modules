#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
    private :
        Contact contacts[8];
    public :
        void    welcome();
        void    add_contact(int i);
        void    search();
};

std::string replace_tab(std::string str);
int contains_nonprint(std::string str);
int isonlywhitespace(std::string str);

#endif