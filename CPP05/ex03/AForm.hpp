#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
class Bureaucrat;

class AForm
{
    private:
        const std::string name;
        bool status;
        const int sign_grade;
        const int exec_grade;
    public:
        AForm();
        AForm(const std::string& Name, int exec, int sign);
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);
        virtual ~AForm();

        // Getters

        std::string getName() const;
        bool getStatus() const;
        int getSignGrade() const;
        int getExecuteGrade() const;


        void beSigned(Bureaucrat& b);
        virtual void execute(Bureaucrat const & executor) const;
        

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
        class ExecuteException : public std::exception
        {
            public:
            const char *what() throw()
            {
                return ("Form cant be executed because it is not signed");
            }
        };


};

std::ostream& operator<<(std::ostream& stream, const AForm& other);




#endif