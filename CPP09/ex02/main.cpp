/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuury <yuury@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 18:14:36 by yuury             #+#    #+#             */
/*   Updated: 2025/10/28 21:52:28 by yuury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    PmergeMe    p;
    
    try
    {
        p.sortAndPrint(ac, av);
    }
    catch(const std::exception& e)
    {
        std::cerr << RED"ERROR :" << e.what() << RESET << std::endl;
        return 1;
    }
    
    return 0;
}