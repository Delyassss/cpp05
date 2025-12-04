/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ildaboun <ildaboun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 16:54:27 by ildaboun          #+#    #+#             */
/*   Updated: 2025/12/04 18:38:51 by ildaboun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int to_code(std::string &name)
{
    std::string levels[3] = {
        "presidential pardon" ,
        "robotomy request",
        "shrubbery creation"
    };
    for (int i = 0; i < 3; i++)
    {
        if (name == levels[i])
            return i;
    }
    return -1;
}

AForm *Intern::makeForm(std::string &form_name, std::string &target)
{
       std::string levels[3] = {
        "presidential pardon" ,
        "robotomy request",
        "shrubbery creation"
    };
    AForm *(Intern::*ptr[3])(std::string &target) = {&Intern::makePres, &Intern::makeRob, &Intern:: makeShrub};
    for (int i = 0; i < 3; i++)
    {
        if (form_name == levels[i])
            return (this->*ptr[i](target));
    }
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