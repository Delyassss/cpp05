/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 10:50:10 by marvin            #+#    #+#             */
/*   Updated: 2025/12/03 10:50:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name("Default"), isSigned(false), gradeToSign(150), gradeToExecute(150)
{
}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
: name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
}

AForm::AForm(const AForm& other)
: name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{
}

AForm& AForm::operator=(const AForm& other)
{
    if (this != &other)
    {
        this->isSigned = other.isSigned;
    }
    return *this;
}
AForm::~AForm()
{
}

void AForm::beSigned(const Bureaucrat &br)
{
    if (br.getGrade() <= gradeToSign)
        this->isSigned = true;
    else
    {
        throw AForm::GradeTooLowException();
    }

}

int AForm::getGradeToExecute() const
{
    return this->gradeToExecute;
}
int AForm::getGradeToSign() const
{
    return this->gradeToSign;
}
bool AForm::getIsSigned() const
{
    return this->isSigned;
}
const std::string& AForm::getName() const
{
    return this->name;
}

const char * AForm::GradeTooHighException::what() const throw()
{
    return "AForm Exception: Grade Too High";
}
const char * AForm::GradeTooLowException::what() const throw()
{
    return "AForm Exception: Grade Too Low";
}
std::ostream& operator<<(std::ostream& os, const AForm& Aform)
{
    os << "AForm Name: " << Aform.getName() << ", Signed: " << (Aform.getIsSigned() ? "Yes" : "No")
       << ", Grade to Sign: " << Aform.getGradeToSign()
       << ", Grade to Execute: " << Aform.getGradeToExecute() << std::endl;
    return os;
}

const char * AForm::FormisnotSigned::what() const throw()
{
    return "AForm Exception: Form is not signed";
}