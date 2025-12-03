/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 12:53:40 by marvin            #+#    #+#             */
/*   Updated: 2025/12/03 12:53:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"


RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("RobotomyRequestForm", 72, 45), target(target)
{}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm(other), target(other.target)
{}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if (this !=  &other)
    {
        AForm::operator=(other);
        this->target = other.target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
    if (!getIsSigned())
    {
        throw FormisnotSigned();
    }
    if (executor.getGrade() > getGradeToExecute())
    {
        throw GradeTooLowException();
    }
    std::cout << "VRRRRRRRRRRRRRRRRRR!!!!!! AHHHHHHHHHHHHHH HELLL ANAHH  WAAAHAT AREE DOINGGG ???????" << std::endl;
    int guessme;
    guessme = rand();
    if (guessme % 2 == 0)
    {
        std::cout << this->target << " has been successfully robotomized" << std::endl;
    }
    else
    {
        std::cout << this->target << " has not been robotomized" << std::endl;
    }
    
}

