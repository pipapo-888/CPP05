#include <iostream>
#include <string>
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Def RRForm", 72, 45), _target("Def Target")
{
	std::cout << "RobotomyRequestForm Default Constructor Called\n";
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("Def RRForm", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm Constructor Called\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj) : AForm(obj), _target(obj._target)
{
	std::cout << "RobotomyRequestForm Copy Constructor Called\n";
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &obj)
{
	std::cout << "RobotomyRequestForm Copy Assignment Operator Called\n";
	if (this != &obj)
		AForm::operator=(obj);
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm Destructor Called\n";
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (this->getIsSigned() == false)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExe())
		throw AForm::GradeTooLowException();

	int rand = 5;

	if (rand % 2 == 0)
		std::cout << "bzzzzzz... " << _target << " has been robotomized successfully";
	else
		std::cout << "Robotomy Failed...";
}
