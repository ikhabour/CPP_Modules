#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name("unnamed"), sign_grade(150), exec_grade(150)
{
    this->status = 0;
}

AForm::AForm(const std::string& Name, int exec, int sign) : name(Name), sign_grade(sign), exec_grade(exec)
{
    this->status = 0;
    if (this->exec_grade < 1 || this->sign_grade < 1)
        throw GradeTooHighException();
    else if (this->exec_grade > 150 || this->sign_grade > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& other) : name(other.name), sign_grade(other.sign_grade), exec_grade(other.sign_grade)
{
    *this = other;
}

AForm& AForm::operator=(const AForm& other)
{
    if (this != &other)
    {
        this->status = other.status;
    }
    return *this;
}

AForm::~AForm() {}

std::string AForm::getName() const
{
    return this->name;
}

bool AForm::getStatus() const
{
    return this->status;
}

int AForm::getSignGrade() const
{
    return this->sign_grade;
}

int AForm::getExecuteGrade() const
{
    return this->exec_grade;
}

void AForm::beSigned(Bureaucrat& b)
{
    if (b.getGrade() > this->sign_grade)
        throw GradeTooLowException();
    this->status = 1;
    std::cout<<b.getName()<<" signed "<<this->getName()<<std::endl;
}

void AForm::execute(Bureaucrat const & executor) const
{
    (void)executor;
}

std::ostream& operator<<(std::ostream& stream, const AForm& other)
{
	stream << "AForm name : " << other.getName() << std::endl;
	stream << "Sign Grade : " << other.getSignGrade() << std::endl;
	stream << "Execute Grade : " << other.getExecuteGrade() << std::endl;
	stream << "Signed : " << other.getStatus();
	return (stream);
}