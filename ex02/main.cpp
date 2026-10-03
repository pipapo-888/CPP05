#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	std::srand(std::time(NULL));

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

	return (0);
}
