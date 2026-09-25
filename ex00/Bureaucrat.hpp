#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <ostream>

class Bureaucrat
{
    private:
        std::string const _name;
        int _grade;
    public:
        Bureaucrat();
        Bureaucrat(const Bureaucrat &obj);
        Bureaucrat(std::string name, int grade);
        void operator=(const Bureaucrat &obj);
        ~Bureaucrat();
        
        std::string getName() const;
        int getGrade() const;

        static void GradeTooHighException();
        static void GradeTooLowException();
        

        Bureaucrat &operator++();
        Bureaucrat operator++(int);
        Bureaucrat &operator--();
        Bureaucrat operator--(int);
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &obj);

#endif