#include <iostream>
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


Intern::Intern()
{
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern &other)
{
	(void)other;
	std::cout << "Intern copy constructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	std::cout << "Intern assignment operator called" << std::endl;
	return *this;
}

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target)
{
	std::string forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm* (Intern::*f[])(const std::string&) = {&Intern::makeFormInstanceShrubbery, &Intern::makeFormInstanceRobotomy, &Intern::makeFormInstancePresidential};

	for (int i = 0; i < 3; ++i)
	{
		if (forms[i] == formName)
		{
			std::cout << "Intern creates " << formName << " Form\n";
			return (this->*f[i])(target);
		}
	}
	throw NoSuchFormException();
}

const char *Intern::NoSuchFormException::what() const throw()
{
	return "No Such Form";
}

AForm* Intern::makeFormInstanceShrubbery(const std::string &target)
{
	AForm *tmp = new ShrubberyCreationForm(target);
	return tmp;
}

AForm* Intern::makeFormInstanceRobotomy(const std::string &target)
{
	AForm *tmp = new RobotomyRequestForm(target);
	return tmp;
}

AForm* Intern::makeFormInstancePresidential(const std::string &target)
{
	AForm *tmp = new PresidentialPardonForm(target);
	return tmp;
}
