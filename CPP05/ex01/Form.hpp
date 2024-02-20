#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
class Bureaucrat;

class Form
{
    private:
        const std::string name;
        bool status;
        const int sign_grade;
        const int exec_grade;
    public:
        Form();
        Form(const std::string& Name, int exec, int sign);
        Form(const Form& other);
        Form& operator=(const Form& other);
        ~Form();

        // Getters

        std::string getName() const;
        int getStatus();
        int getSignGrade() const;
        int getExecuteGrade() const;


        void beSigned(Bureaucrat& b);
        

        // Exception classes

        class GradeTooHighException : public std::exception
        {
            public:
                const char *what() throw()
                {
                    return ("Grade too High");
                }
        };
        class GradeTooLowException : public std::exception
        {
            public:
            const char *what() throw()
            {
                return ("Grade too Low");
            }
        };


};





#endif