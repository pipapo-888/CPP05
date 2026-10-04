#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Bureaucrat a("A", 2);
		Form form1("form1", 10, 3);
		Form form2("form2", 1, 1);
		
		std::cout << a << form1 << form2;

		a.signForm(form1);
		a.signForm(form2);
		std::cout << a << form1 << form2;

		++a;
		a.signForm(form2);
		std::cout << a << form1 << form2;

	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "------------\n";

	try
	{
		Form form3("x", 0, 10);
		std::cout << form3;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "------------\n";

	try
	{
		Form form4("x", 10, 151);
		std::cout << form4;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "------------\n";

	return (0);
}
