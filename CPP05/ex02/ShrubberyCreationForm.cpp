#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("none", 137, 145), target("none") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm(target + "_shrubbery", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other)
{
    *this = other;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        this->target = other.target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if (!this->getStatus())
        throw ShrubberyCreationForm::ExecuteException();
    if (executor.getGrade() > this->getExecuteGrade())
        throw ShrubberyCreationForm::GradeTooLowException();
    std::ofstream file((this->target + "_shrubbery").c_str());
    if (!file.is_open())
        std::cout<<"Error opening file"<<std::endl;
    const char *tree =
        "       _-_\n       "
        "    /~~   ~~\\\n   "
        " /~~         ~~\\\n"
        "{               }\n"
        " \\  _-     -_  /\n"
        "   ~  \\ //  ~\n   "
        "_- -   | | _- _\n  "
        "  _ -  | |   -_\n  "
        "      // \\        ";
    file << tree << std::endl;
    file.close();
}