#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "AForms.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string gName) : AForms("ShrubberyCreationForm", 145, 137)
{
	this->target = gName;
	std::cout << "ShrubberyCreationForm constructer called" << std::endl;
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
    "        akarafi {{}\n"
    "        , -=-~{ .-^- _\n"
    "                `}\n"
    "                 {"
    << std::endl;
}
