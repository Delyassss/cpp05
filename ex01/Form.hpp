/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 15:12:56 by marvin            #+#    #+#             */
/*   Updated: 2025/12/01 15:12:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>
#include <string.h>
#include "Bureaucrat.hpp"

class Form
{
    private :
    const std::string   name;
    bool                isSigned;
    const int           gradeToSign;
    const int           gradeToExecute;

    public :
    Form();
    Form(const std::string& name, int gradeToSign, int gradeToExecute);
    Form(const Form& other);
    Form& operator=(const Form& other);
    ~Form();
    const std::string& getName() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    void beSigned(const Bureaucrat& bureaucrat);
    class GradeTooHighException : public std::exception
    {
        public : 
            virtual const char * what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
         public : 
            virtual const char * what() const throw();
    };

};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif