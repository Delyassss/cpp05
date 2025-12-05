/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 13:45:19 by marvin            #+#    #+#             */
/*   Updated: 2025/12/03 13:45:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <ctime>
#include <cstdlib>
#include "Intern.hpp"


int main ()
{
    std::srand(time(0)); // we manipulate the start needle by using the time (ofc because we don wanna start at the same point)
    Bureaucrat big("SBA3", 1);
    Bureaucrat mid("SB3A", 43);
    Intern slave;
    AForm *form;
    form = slave.makeForm("shrubbery creation", "Ilyass");
    if (form)
    {
        form->beSigned(big);
        mid.executeForm(*form);
        delete form;
    }
}