#ifndef AFORM_HPP
#define AFORM_HPP

#include <ostream>
#include <exception>
#include <string>

class Bureaucrat;

class AForm
{

private:
	const std::string _name;
	bool _isSigned;
	const int _gradeToSign;
	const int _gradeToExe;

public:
	AForm();
	AForm(const std::string &name, int GradeToSign, int GradeToExe);
	AForm(const AForm &obj);
	AForm &operator=(const AForm &obj);
	virtual ~AForm();

	const std::string &getName() const;
	bool getIsSigned() const;
	int getGradeToSign() const;
	int getGradeToExe() const;
	void beSigned(const Bureaucrat &obj);
	virtual void execute(Bureaucrat const & executor) const = 0;

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

	class FormNotSignedException : public std::exception{
		public:
			const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &out, const AForm &obj);

#endif