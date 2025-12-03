/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 13:28:31 by marvin            #+#    #+#             */
/*   Updated: 2025/12/01 13:28:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"


int main()
{
    try 
    {
        Bureaucrat br1("ilyass", 50);
        std::cout << br1;
        Bureaucrat br2("imane",43);
        std::cout << br2;
        Bureaucrat br3("maroua", 27);
        br1.decrementGrade();
        Form form1("Form1", 45, 30);
        br2.signForm(form1);
        std::cout << form1;
        Form form2("Form2", 1, 2);
        br3.signForm(form2);
        std::cout << form2;


   

    }
    catch (Bureaucrat::GradeTooHighException &e)
    {
       std::cout << e.what() << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException &e)
    {
        std::cout << e.what() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

}