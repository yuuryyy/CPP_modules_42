/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuury <yuury@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 21:41:00 by yuury             #+#    #+#             */
/*   Updated: 2025/10/24 21:42:45 by yuury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"


int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Error: invalid Number of arguments";
        return 1;
    }
    
    RPN a;

    a.RPNcalculator(std::string(av[1]));
    return 0;
}