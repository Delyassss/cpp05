/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ildaboun <ildaboun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 16:52:33 by ildaboun          #+#    #+#             */
/*   Updated: 2025/12/04 18:30:56 by ildaboun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "ShrubberyCreationForm.hpp"
#include  "PresidentialPardonForm.hpp"
#include  "RobotomyRequestForm.hpp"

class Afrom;
class Intern
{
    public :
        AForm *makeForm(std::string &form_name, std::string &target);
        AForm *makeShrub(std::string &target);
        AForm *makeRob(std::string &target);
        AForm *makePres(std::string &target);
};

#endif 