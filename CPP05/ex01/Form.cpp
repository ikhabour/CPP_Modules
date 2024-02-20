#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("unnamed"), sign_grade(150), exec_grade(150)
{
    this->status = 0;
}

Form::Form(const std::string& Name, int exec, int sign) : name(Name), sign_grade(sign), exec_grade(exec)
{
    this->status = 0;
    if (this->exec_grade < 1 || this->sign_grade < 1)
        throw GradeTooHighException();
    else if (this->exec_grade > 150 || this->sign_grade > 150)
        throw GradeTooLowException();
}

Form::Form(const Form& other) : name(other.name), sign_grade(other.sign_grade), exec_grade(other.sign_grade)
{
    *this = other;
}

Form& Form::operator=(const Form& other)
{
    if (this != &other)
    {
        this->status = other.status;
    }
    return *this;
}

Form::~Form() {}

std::string Form::getName() const
{
    return this->name;
}

int Form::getStatus()
{
    return this->status;
}

int Form::getSignGrade() const
{
    return this->sign_grade;
}

int Form::getExecuteGrade() const
{
    return this->exec_grade;
}

void Form::beSigned(Bureaucrat& b)
{
    if (b.getGrade() > this->sign_grade)
        throw GradeTooLowException();
    this->status = 1;
    std::cout<<b.getName()<<" signed "<<this->getName()<<std::endl;
}