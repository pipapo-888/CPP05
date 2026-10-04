#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include <exception>
#include "AForm.hpp"

class Intern
{
private:
	AForm* makeFormInstanceShrubbery(const std::string &target);
	AForm* makeFormInstanceRobotomy(const std::string &target);
	AForm* makeFormInstancePresidential(const std::string &target);

public:
	Intern();
	Intern(const Intern &other);
	Intern &operator=(const Intern &other);
	~Intern();

	AForm *makeForm(const std::string &formName, const std::string &target);


	class NoSuchFormException : public std::exception
	{
	public:
		const char* what() const throw();
	};
};

#endif
