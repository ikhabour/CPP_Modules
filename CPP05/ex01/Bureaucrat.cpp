#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string Name, int Grade) : name(Name)
{
    if (Grade < 1)
        throw GradeTooHighException();
    else if (Grade > 150)
        throw GradeTooLowException();
    else
        this->grade = Grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name)
{
    *this = other;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)
    {
        this->grade = other.grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat() {}

int Bureaucrat::getGrade() const
{
    return (this->grade);
}

std::string Bureaucrat::getName() const
{
    return (this->name);
}

void Bureaucrat::increment()
{
    if (this->grade - 1 < 1)
        throw GradeTooHighException();
    this->grade--;
}

void Bureaucrat::decrement()
{
    if (this->grade + 1 > 150)
        throw GradeTooLowException();
    this->grade++;
}


void    Bureaucrat::signForm(Form& f)
{
    try
    {
        f.beSigned(*this);
    }
    catch(Form::GradeTooLowException &e)
    {
        std::cout<<this->name<<" couldn't sign "<<f.getName()<<" because : ";
        std::cout<<e.what()<<std::endl;
    }
}

std::ostream& operator<<(std::ostream& stream, const Bureaucrat& obj)
{
    stream << obj.getName() << " , bureaucrat grade " << obj.getGrade();
    return stream;
}