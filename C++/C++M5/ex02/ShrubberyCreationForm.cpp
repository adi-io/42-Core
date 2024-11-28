#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "AForms.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string gName) : AForm("ShrubberyCreationForm", 145, 137)
{
	this->target = gName;
	std::cout << "ShrubberyCreationForm constructer called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other), target(other.target)
{
    std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        this->target = other.target;
        std::cout << "ShrubberyCreationForm copy assignment operator called" << std::endl;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

void ShrubberyCreationForm::action() const
{
    std::ofstream outFile(this->target + "_shrubbery");
    if (!outFile)
	{
        std::cerr << "can't open/create shrubbery" << std::endl;
        return ;
    }
    outFile <<
    "            # #### ####\n"
    "        ### \\/#|### |/####\n"
    "        ##\\/#/ \\||/##/_/##/_#\n"
    "       ###  \\/###|/ \\/ # ###\n"
    "    ##_\\_#\\_\\## | #/###_/_####\n"
    "    ## #### # \\ #| /  #### ##/##\n"
    "    __#_--###`  |{,###---###-~\n"
    "                \\ }{\n"
    "                }}{\n"
    "                }}{\n"
    "        agadkar {{}\n"
    "        , -=-~{ .-^- _\n"
    "                `}\n"
    "                 {"
    << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    AForm::execute(executor);
    this->action();
}
