#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include "Bureaucrat.hpp"

class Form
{

private:
	const std::string _name;
	bool _isSinged;
	const int _gradeToSign;
	const int _gradeToExe;

public:
	Form();
	Form(std::string name, int toSign, int toExe);
	Form(const Form &obj);
	Form &operator=(const Form &obj);
	~Form();

	const std::string &getName() const;
	bool getIsSigned() const;
	int getGradeToSign() const;
	int getGradeToExe() const;
	void beSigned(const Bureaucrat &obj);

	class GradeTooHighException : public std::exception
	{
	public:
		const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &out, const Form &obj);

#endif