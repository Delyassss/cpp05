/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 10:50:37 by marvin            #+#    #+#             */
/*   Updated: 2025/12/03 10:50:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AForm_HPP
#define AForm_HPP

#include <iostream>
#include <stdexcept>
#include <string>
class Bureaucrat;

class AForm
{
    private :
    const std::string   name;
    bool                isSigned;
    const int           gradeToSign;
    const int           gradeToExecute;

    public :
    AForm();
    AForm(const std::string& name, int gradeToSign, int gradeToExecute);
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);
    virtual ~AForm();
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
    class FormisnotSigned : public std::exception
    {
         public : 
            virtual const char * what() const throw();
    };

    virtual void execute(Bureaucrat const & executor) const = 0;

};

std::ostream& operator<<(std::ostream& os, const AForm& aform);

#endif