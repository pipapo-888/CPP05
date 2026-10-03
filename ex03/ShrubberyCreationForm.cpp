#include <iostream>
#include <fstream>
#include <string>
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Def SCForm", 145, 137), _target("Def Target")
{
	std::cout << "ShrubberyCreationForm Default Constructor Called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("Def SCForm", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm Constructor Called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj) : AForm(obj), _target(obj._target)
{
	std::cout << "ShrubberyCreationForm Copy Constructor Called\n";
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj)
{
	std::cout << "ShrubberyCreationForm Copy Assignment Operator Called\n";
	if (this != &obj)
		AForm::operator=(obj);
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm Destructor Called\n";
}

const char *ShrubberyCreationForm::outfErrorException::what() const throw()
{
	return "Error: Could not open file for writing.";
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (this->getIsSigned() == false)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExe())
		throw AForm::GradeTooLowException();

	std::ofstream outfile((_target + "_shrubbery").c_str());
	if (!outfile)
		throw outfErrorException();

	outfile << "                        	 &&\n"
			<< "                          &&& & &&\n"
			<< "                        &&& &&  & &&\n"
			<< "                    && &\\/&\\|& ()|/ @, &&\n"
			<< "                    &\\/(/&/&||/& /_/)_&/_&\n"
			<< "                 &() &\\/&|()|/&\\/ '%\" & ()\n"
			<< "                &_\\_&&_\\ |& |&&/&__%_/_& &&\n"
			<< "              &&   && & &| &| /& & % ()& /&&\n"
			<< "               ()&_---()&\\&\\|&&-&&--%---()~\n"
			<< "                          \\||||/\n"
			<< "                            ||||\n"
			<< "                            ||||\n"
			<< "                            ||||\n"
			<< "                            ||||\n"
			<< "                            ||||\n"
			<< "                           /||||\n"
			<< "                          //||||\\\n"
			<< "                     , -=-~  .-^- _-=\\\n";

	outfile.close();
}
