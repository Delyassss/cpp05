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


int main()
{
    try 
    {
        Bureaucrat br1("ilyass", 150);
        std::cout << br1;
        Bureaucrat br2("imane", 1);
        std::cout << br2;
        br1.decrementGrade();
        br2.incrementGrade();

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