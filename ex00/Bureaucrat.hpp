#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>

class Bureaucrat
{
    private:
        std::string const _name;
        int _grade;
    public:
        Bureaucrat();
        Bureaucrat(const Bureaucrat &obj);
        void Bureaucrat::operator=(const Bureaucrat &obj);
        ~Bureaucrat();
        
        std::string getName();
        int getGrade();

        static void GradeTooHighException();
        static void GradeTooLowException();
        

}

#endif