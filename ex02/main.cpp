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


int main ()
{
    std::srand(time(0)); // we manipulate the start needle by using the time (ofc because we dont wanna start at the same point)
    Bureaucrat big("SBA3", 1);
    Bureaucrat mid("SB3A", 43);
    Bureaucrat small("DBA3", 150);
    ShrubberyCreationForm shrub("home");
    shrub.beSigned(mid);
    mid.executeForm(shrub);
    small.executeForm(shrub); // should throw an exception
    RobotomyRequestForm robot("Bender");
    robot.beSigned(big); // signed by big but mid will execute
    mid.executeForm(robot);
    PresidentialPardonForm pres("SOLARIS");
    pres.beSigned(big);
    big.executeForm(pres);
    
}