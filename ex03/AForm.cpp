#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("Default AForm"), _isSigned(false), _gradeToSign(100), _gradeToExe(50)
{
	std::cout << "AForm Default Constructor Called\n";
}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExe) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExe(gradeToExe)
{
	std::cout << "AForm Constructor Called\n";
	if (gradeToSign < 1 || gradeToExe < 1)
		throw AForm::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExe > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &obj) : _name(obj._name), _isSigned(obj._isSigned), _gradeToSign(obj._gradeToSign), _gradeToExe(obj._gradeToExe)
{
	std::cout << "AForm Copy Constructor Called\n";
}

AForm &AForm::operator=(const AForm &obj)
{
	std::cout << "AForm Copy Assignment Operator Called\n";
	_isSigned = obj._isSigned;
	return *this;
}

AForm::~AForm()
{
	std::cout << "AForm Destructor Called\n";
}

const std::string &AForm::getName() const
{
	return _name;
}

bool AForm::getIsSigned() const
{
	return _isSigned;
}

int AForm::getGradeToSign() const
{
	return _gradeToSign;
}

int AForm::getGradeToExe() const
{
	return _gradeToExe;
}

void AForm::beSigned(const Bureaucrat &obj)
{
	if (obj.getGrade() > _gradeToSign)
		throw AForm::GradeTooLowException();
	_isSigned = true;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return "Form is not signed";
}

std::ostream &operator<<(std::ostream &out, const AForm &obj)
{
	out << "AForm Name: " << obj.getName() << ", Is Signed: " << (obj.getIsSigned() ? "True" : "False") << ", Grade to Sign: " << obj.getGradeToSign() << ", Grade to Execute: " << obj.getGradeToExe() << std::endl;
	return out;
}
