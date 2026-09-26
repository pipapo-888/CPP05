#include <iostream>
#include "Form.hpp"

Form::Form() : _name("Default Form"), _isSinged(false), _gradeToSign(100), _gradeToExe(50)
{
	std::cout << "Form Default Constructor Called\n";
}

Form::Form(const std::string &name, int gradeToSign, int gradeToExe) : _name(name), _isSinged(false), _gradeToSign(gradeToSign), _gradeToExe(gradeToExe)
{
	std::cout << "Form Constructor Called\n";
	if (gradeToSign < 1 || gradeToExe < 1)
		throw Form::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExe > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &obj) : _name(obj._name), _isSinged(obj._isSinged), _gradeToSign(obj._gradeToSign), _gradeToExe(obj._gradeToExe)
{
	std::cout << "Form Copy Constructor Called\n";
}

Form &Form::operator=(const Form &obj)
{
	std::cout << "Form Copy Assignment Operator Called\n";
	_isSinged = obj._isSinged;
	return *this;
}

Form::~Form()
{
	std::cout << "Form Destructor Called\n";
}

const std::string &Form::getName() const
{
	return _name;
}

bool Form::getIsSigned() const
{
	return _isSinged;
}

int Form::getGradeToSign() const
{
	return _gradeToSign;
}

int Form::getGradeToExe() const
{
	return _gradeToExe;
}

void Form::beSigned(const Bureaucrat &obj)
{
	if (obj.getGrade() > _gradeToSign)
		throw Form::GradeTooLowException();
	_isSinged = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Form Grade is too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Form Grade is too low";
}

std::ostream &operator<<(std::ostream &out, const Form &obj)
{
	out << "Form Name: " << obj.getName() << ", Is Signed: " << (obj.getIsSigned() ? "True" : "False") << ", Grade to Sign: " << obj.getGradeToSign() << ", Grade to Execute: " << obj.getGradeToExe();
	return out;
}