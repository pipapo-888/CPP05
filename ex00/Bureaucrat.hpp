#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <ostream>
#include <exception>

class Bureaucrat
{
private:
	std::string const _name;
	int _grade;

public:
	Bureaucrat();
	Bureaucrat(const Bureaucrat &obj);
	Bureaucrat(const std::string &name, int grade);
	Bureaucrat &operator=(const Bureaucrat &obj);
	~Bureaucrat();

	std::string getName() const;
	int getGrade() const;

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

	Bureaucrat &operator++();
	Bureaucrat operator++(int);
	Bureaucrat &operator--();
	Bureaucrat operator--(int);
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &obj);

#endif