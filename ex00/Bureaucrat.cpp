#include <iostream>
#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat() : _name("Default"), _grade(50)
{
    std::cout << "Default Constructor Called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string &name, int grade) : _name(name), _grade(grade)
{
    std::cout << "Constructor Called" << std::endl;
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj) : _name(obj._name), _grade(obj._grade)
{
    std::cout << "Copy Constructor Called" << std::endl;
}

void Bureaucrat::operator=(const Bureaucrat &obj)
{
    std::cout << "Copy Assignment Operator Called";
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Destructor Called" << std::endl;
}

std::string Bureaucrat::getName() const
{
    return _name;
}

int Bureaucrat::getGrade() const
{
    return _grade;
}

static void Bureaucrat::GradeTooHighException()
{

}

static void Bureaucrat::GradeTooLowException()
{

}

Bureaucrat &Bureaucrat::operator++()
{
    if (_grade <= 1)
        throw GradeTooHighException();
    _grade--;
    return(*this);
}

Bureaucrat Bureaucrat::operator++(int)
{
    if (_grade <= 1)
        throw GradeTooHighException();
    Bureaucrat tmp(*this);
    _grade--;
    return tmp;
}

Bureaucrat &Bureaucrat::operator--()
{
    if (_grade >= 150)
        throw GradeTooLowException();
    _grade++;
    return (*this);
}

Bureaucrat Bureaucrat::operator--(int)
{
    if (_grade >= 150)
        throw GradeTooLowException();
    Bureaucrat tmp(*this);    
    _grade++;
    return tmp;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &obj)
{
    out << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".\n";
    return out;
}