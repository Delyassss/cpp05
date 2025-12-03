/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 11:09:50 by marvin            #+#    #+#             */
/*   Updated: 2025/12/03 11:09:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include <string>

class AForm;

class Bureaucrat
{
    private :
        const std::string name;
        int grade;
    public :
    Bureaucrat();
    Bureaucrat(const std::string& name, int grade);
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();
    const std::string& getName() const;
    int getGrade() const;
    void incrementGrade();
    void decrementGrade();
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
    void signForm(AForm& aform);
    void executeForm(AForm const & form) const;
};

std::ostream &operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif
