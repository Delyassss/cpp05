/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 21:42:56 by marvin            #+#    #+#             */
/*   Updated: 2025/12/05 21:42:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm("PresidentialPardonForm", 25, 5), target(target)
{}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
    : AForm(other), target(other.target)
{}
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    if (this !=  &other)
    {
        AForm::operator=(other);
        this->target = other.target;
    }
    return *this;
}
PresidentialPardonForm::~PresidentialPardonForm() {}


void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
    if (!getIsSigned())
    {
        throw FormisnotSigned();
    }
    if (executor.getGrade() > getGradeToExecute())
    {
        throw GradeTooLowException();
    } 
    else
    {
        std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
    }
}