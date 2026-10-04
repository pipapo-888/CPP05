#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
	std::srand(std::time(NULL));

	AForm* forms[4] = {NULL, NULL, NULL, NULL};
	try
	{
		Intern intern;

		forms[0] = intern.makeForm("shrubbery creation", "banana");
		std::cout << *forms[0] << std::endl;

		forms[1] = intern.makeForm("robotomy request", "Bob");
		std::cout << *forms[1] << std::endl;

		forms[2] = intern.makeForm("presidential pardon", "Criminal");
		std::cout << *forms[2] << std::endl;

		forms[3] = intern.makeForm("no exist", "banana");
		std::cout << *forms[3] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "------------\n";

	try
	{
		ShrubberyCreationForm SCF("Garden");
		Bureaucrat c("C", 2);
		std::cout << SCF.getName() << " " << SCF.getIsSigned() << " " << SCF.getGradeToSign() << " " << SCF.getGradeToExe() << std::endl;
		c.executeForm(SCF);
		c.signAForm(SCF);
		c.executeForm(SCF);

		Bureaucrat lowGradeSign("LowSign", 150);
		ShrubberyCreationForm SCF2("Garden2");
		lowGradeSign.signAForm(SCF2);

		Bureaucrat lowGradeExe("LowExe", 140);
		lowGradeExe.executeForm(SCF);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "------------\n";

	try
	{
		RobotomyRequestForm RRF("Target");
		Bureaucrat b("B", 2);
		std::cout << RRF.getName() << " " << RRF.getIsSigned() << " " << RRF.getGradeToSign() << " " << RRF.getGradeToExe() << std::endl;
		b.executeForm(RRF);
		b.signAForm(RRF);
		for (int i = 0; i < 10; i++)
			b.executeForm(RRF);

		Bureaucrat lowGradeSign("LowSign", 80);
		RobotomyRequestForm RRF2("Target2");
		lowGradeSign.signAForm(RRF2);

		Bureaucrat lowGradeExe("LowExe", 50);
		lowGradeExe.executeForm(RRF);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "------------\n";

	try
	{
		PresidentialPardonForm PPF("Criminal");
		Bureaucrat a("A", 2);
		std::cout << PPF.getName() << " " << PPF.getIsSigned() << " " << PPF.getGradeToSign() << " " << PPF.getGradeToExe() << std::endl;
		a.executeForm(PPF);
		a.signAForm(PPF);
		a.executeForm(PPF);

		Bureaucrat lowGradeSign("LowSign", 30);
		PresidentialPardonForm PPF2("Criminal2");
		lowGradeSign.signAForm(PPF2);

		Bureaucrat lowGradeExe("LowExe", 10);
		lowGradeExe.executeForm(PPF);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < 4; i++)
		delete forms[i];

	return (0);
}
