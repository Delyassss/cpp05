/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 15:24:54 by marvin            #+#    #+#             */
/*   Updated: 2025/12/01 15:24:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name("Default"), isSigned(false), gradeToSign(150), gradeToExecute(150)
{
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
: name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
}

Form::Form(const Form& other)
: name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{
}

Form& Form::operator=(const Form& other)
{
    if (this != &other)
    {
        this->isSigned = other.isSigned;
    }
    return *this;
}
Form::~Form()
{
}

void Form::beSigned(const Bureaucrat &br)
{
    if (br.getGrade() <= gradeToSign)
        this->isSigned = true;
    else
    {
        throw Form::GradeTooLowException();
    }

}

int Form::getGradeToExecute() const
{
    return this->gradeToExecute;
}
int Form::getGradeToSign() const
{
    return this->gradeToSign;
}
bool Form::getIsSigned() const
{
    return this->isSigned;
}
const std::string& Form::getName() const
{
    return this->name;
}

const char * Form::GradeTooHighException::what() const throw()
{
    return "Form Exception: Grade Too High";
}
const char * Form::GradeTooLowException::what() const throw()
{
    return "Form Exception: Grade Too Low";
}
std::ostream& operator<<(std::ostream& os, const Form& form)
{
    os << "Form Name: " << form.getName() << ", Signed: " << (form.getIsSigned() ? "Yes" : "No")
       << ", Grade to Sign: " << form.getGradeToSign()
       << ", Grade to Execute: " << form.getGradeToExecute() << std::endl;
    return os;
}