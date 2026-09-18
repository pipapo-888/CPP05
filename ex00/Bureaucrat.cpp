#include <iostream>
#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat() : _name("Default"), _grade(50)
{
    std::cout << "Default Constructor Called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
    std::cout << "Default Constructor Called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj) : _name(obj.name), _grade(obj.grade)
{
    std::cout << "Copy Constructor Called" << std::endl;
}

void Bureaucrat::operator=(const Bureaucrat &obj)
{
    std::cout << "Copy Assignment Operator Called"
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Destructor Called" << std::endl;
}

std::string Bureaucrat::getName()
{
    return _name;
}

int Bureaucrat::getGrade()
{
    return _grade;
}

