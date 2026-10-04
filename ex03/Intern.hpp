#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include "AForm.hpp"

class Intern
{
public:
	Intern();
	Intern(const Intern &other);
	Intern &operator=(const Intern &other);
	~Intern();

	AForm *makeForm(const std::string &formName, const std::string &target);

	AForm* makeFormInstanceShrubbery(const std::string &target);

	class NoSuchFormException : public std::exception
	{
	public:
		const char* what() const throw();
	};
};

#endif
