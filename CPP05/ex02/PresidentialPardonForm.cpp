#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("none", 5, 25), target("none") {}



PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm(target, 5, 25), target(target) {}


PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other)
{
    *this = other;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        this->target = other.target;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (!this->getStatus())
        throw AForm::ExecuteException();
    if (this->getExecuteGrade() > executor.getGrade())
        throw AForm::GradeTooLowException();
    std::cout<<this->target<<" has been pardoned by Zaphod Beeblebrox."<<std::endl;
}