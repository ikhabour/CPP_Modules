#include "Intern.hpp"


Intern::Intern() {}


Intern::Intern(const Intern& other)
{
    *this = other;
}

Intern& Intern::operator=(const Intern& other)
{
    (void)other;
    return *this;
}

Intern::~Intern() {}


int form_type(const std::string &type)
{
    if (type == "presidential request")
        return (0);
    if (type == "shrubbery request")
        return (1);
    if (type == "robotomy request")
        return (2);
    return 3;
}

AForm* Intern::makeForm(const std::string& form, const std::string &target)
{
	int type = 3;
    AForm* f;
    type = form_type(form);
    switch(type)
    {
        case 0:
            f = new PresidentialPardonForm(target);
            std::cout<<"Intern creates "<<form<<std::endl;
            break;
        case 1:
            f = new ShrubberyCreationForm(target);
            std::cout<<"Intern creates "<<form<<std::endl;
            break;
        case 2:
            f = new RobotomyRequestForm(target);
            std::cout<<"Intern creates "<<form<<std::endl;
            break;
        default:
            f = NULL;
            std::cout<<"Unknown form name."<<std::endl;
            break;
    }
    return (f);
}