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
		b.executeForm(RRF);
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
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}
