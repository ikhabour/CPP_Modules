#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <ctime>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : AForm("none", 45, 72), target("none") {}


RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm(target, 45, 72), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other)
{
    *this = other;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        this->target = other.target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void    RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    std::srand(std::time(0));

    int randomNum = rand() % 2;
    if (!this->getStatus())
    {
        std::cout<<"Robotomy Failed."<<std::endl;
        throw AForm::ExecuteException();
    }
    if (executor.getGrade() > this->getExecuteGrade())
    {
        std::cout<<"Robotomy Failed."<<std::endl;
        throw AForm::ExecuteException();
    }
    std::cout<<"*noises*"<<std::endl;
    if (randomNum == 0)
        std::cout<<this->target<<" has been robotomized successfully"<<std::endl;
    else
        std::cout<<"Robotomy Failed."<<std::endl;
}