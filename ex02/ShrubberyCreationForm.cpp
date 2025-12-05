/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 11:14:34 by marvin            #+#    #+#             */
/*   Updated: 2025/12/03 11:14:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", 145, 137), target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other), target(other.target)
{}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this !=  &other)
    {
        AForm::operator=(other);
        this->target = other.target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
    if (!getIsSigned())
    {
        throw FormisnotSigned();
    }
    if (executor.getGrade() > getGradeToExecute())
    {
        throw GradeTooLowException();
    }
    std::ofstream s;

    s.open((target + "_shrubbery").c_str());
    if (!s.is_open())
    {
        throw  std::ios_base::failure("you have a problem with opening the file !");
    }

    s << "               O              " << std::endl;
    s << "              *** " << std::endl;
    s << "             **O** " << std::endl;
    s << "            ******* " << std::endl;
    s << "           ********* " << std::endl;
    s << "          *********** " << std::endl;
    s << "           ******o** " << std::endl;
    s << "          *********** " << std::endl;
    s << "         ****o******** " << std::endl;
    s << "        *************** " << std::endl;
    s << "       ****o***o******** " << std::endl;
    s << "      ******************* " << std::endl;
    s << "    *********************** " << std::endl;
    s << "        *****O*********** " << std::endl;
    s << "       **********o******** " << std::endl;
    s << "      ****************o**** " << std::endl;
    s << "    **O******************** " << std::endl;
    s << "   ***********o********O**** " << std::endl;
    s << "  ***************************** " << std::endl;
    s << "      ********************* " << std::endl;
    s << "    ***o******************* " << std::endl;
    s << "   ***********o*******o***** " << std::endl;
    s << "  *************************** " << std::endl;
    s << " ***********************O***** " << std::endl;
    s << " ***O*************************** " << std::endl;
    s << "***********************************" << std::endl;
    s << "    ************************* " << std::endl;
    s << "  *******o********o********** " << std::endl;
    s << " ***************************** " << std::endl;
    s << " **************o**************** " << std::endl;
    s << "*************************O*******" << std::endl;
    s << " *****O*****************************" << std::endl;
    s << "**************o************************" << std::endl;
    s << "    *************************** " << std::endl;
    s << "    *************o*************** " << std::endl;
    s << "   ***********o******************* " << std::endl;
    s << "   **************************O******" << std::endl;
    s << "  ***o******************O************" << std::endl;
    s << "***o***********o****************o******" << std::endl;
    s << "            #######            " << std::endl;
    s << "            #######            " << std::endl;
    s << "            #######            " << std::endl;
    s << "          ###########          " << std::endl;
    s << "          ###########          " << std::endl;

    s.close();
}
