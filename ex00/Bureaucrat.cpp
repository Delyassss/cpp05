/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 10:30:55 by marvin            #+#    #+#             */
/*   Updated: 2025/12/01 10:30:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default"), grade(150)
{
}
Bureaucrat::~Bureaucrat()
{

}

Bureaucrat::Bureaucrat(const Bureaucrat &br) : name(br.name), grade(br.grade)
{  

}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name), grade(grade)
{
    if (getGrade() > 150) {throw (Bureaucrat::GradeTooLowException());}
    if (getGrade() < 1) {throw (Bureaucrat::GradeTooHighException());}
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)
    {
        this->grade = other.grade;
    }
    return *this;
}

const std::string& Bureaucrat::getName() const
{
    return this->name;
}
int Bureaucrat::getGrade() const
{
    return this->grade;
}

void Bureaucrat::decrementGrade()
{
    if (grade >= 150)
    {
        throw Bureaucrat::GradeTooLowException();
    }
    this->grade++;
}

void Bureaucrat::incrementGrade()
{
    if (grade <= 1)
    {
        throw Bureaucrat::GradeTooHighException();
    }
    this->grade--;
}

std::ostream &operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
    os << bureaucrat.getName() << " Bureaucrat grade " << bureaucrat.getGrade() << std::endl;
    return os;
}

const char * Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("grade too High ( grade < 1 )!! ");
}

const char * Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade to Low ( grade > 150 )");
}








