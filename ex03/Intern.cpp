/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 16:54:27 by ildaboun          #+#    #+#             */
/*   Updated: 2025/12/05 14:21:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
}
Intern::~Intern()
{
}
Intern::Intern(const Intern &other)
{
    (void)other;
}
Intern &Intern::operator=(const Intern &other)
{
    (void)other;
    return (*this);
}

AForm *Intern::makeForm(std::string form_name, std::string target)
{
       std::string levels[3] = {
        "presidential pardon" ,
        "robotomy request",
        "shrubbery creation"
    };
    AForm *(Intern::*ptr[3])(std::string &target)   = 
    {
        &Intern::makePres,
        &Intern::makeRob,
        &Intern:: makeShrub
    };
    
    for (int i = 0; i < 3; i++)
    {
        if (form_name == levels[i])
        {
            std::cout << "Intern creates " << form_name << std::endl;
            return (this->*ptr[i])(target);
        }
    }
    std::cout << "Intern cannot create " << form_name << " because it doesn't exist !" << std::endl;
   return (NULL);
}

AForm *Intern::makePres(std::string &target)
{
    return (new PresidentialPardonForm(target));
}

AForm *Intern::makeRob(std::string &target)
{
    return (new RobotomyRequestForm(target));
}

AForm *Intern::makeShrub(std::string &target)
{
    return (new ShrubberyCreationForm(target));
}