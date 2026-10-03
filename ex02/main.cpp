#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try{
		PresidentialPardonForm PPF("Criminal");
		std::cout << PPF.getName();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	// try
	// {
	// 	Bureaucrat a("A", 2);
	// 	AForm form1("form1", 10, 3);
	// 	AForm form2("form2", 1, 1);
		
	// 	std::cout << a << form1 << form2;

	// 	a.signAForm(form1);
	// 	a.signAForm(form2);
	// 	std::cout << a << form1 << form2;

	// 	++a;
	// 	a.signAForm(form2);
	// 	std::cout << a << form1 << form2;

	// }
	// catch (const std::exception &e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
	// std::cout << "------------\n";
	return (0);
}