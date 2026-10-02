#include <iostream>
#include <string>
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Def PPForm", 25, 5), _target("Def Target")
{
    std::cout << "PPF Default Constructor Called \n";
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) :  AForm("Def PPForm", 25, 5), _target(target)
{
	std::cout << "PresidentialPardonForm Constructor Called\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj) : AForm(obj), _target(obj._target)
{
	std::cout << "PresidentialPardonForm Copy Constructor Called\n";
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &obj)
{
	std::cout << "PresidentialPardonForm Copy Assignment Operator Called\n";
    if (this != &obj)
		AForm::operator=(obj);
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm Destructor Called\n";
}