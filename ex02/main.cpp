#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main()
{
	try
	{
		Bureaucrat a("A", 2);
		AForm form1("form1", 10, 3);
		AForm form2("form2", 1, 1);
		
		std::cout << a << form1 << form2;

		a.signAForm(form1);
		a.signAForm(form2);
		std::cout << a << form1 << form2;

		++a;
		a.signAForm(form2);
		std::cout << a << form1 << form2;

	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "------------\n";

	try
	{
		AForm form3("x", 0, 10);
		std::cout << form3;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "------------\n";

	try
	{
		AForm form4("x", 10, 151);
		std::cout << form4;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "------------\n";

	// try
	// {
	// 	Bureaucrat a("B", 0);
	// 	std::cout << a;
	// }
	// catch (const std::exception &e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }

	// std::cout << "------------\n";
	// try
	// {
	// 	Bureaucrat a("C", 148);
	// 	std::cout << a;
	// 	--a;
	// 	std::cout << a;
	// 	--a;
	// 	std::cout << a;
	// 	--a;
	// 	std::cout << a;
	// }
	// catch (const std::exception &e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }

	return (0);
}