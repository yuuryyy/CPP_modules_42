/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychagri <ychagri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 23:16:25 by yuury             #+#    #+#             */
/*   Updated: 2025/10/30 21:16:33 by ychagri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "BitcoinExchange.hpp"

int error(std::string msg)
{
    std::cerr << "Error: "<< msg << std::endl;
    return 1;
}

int main(int ac, char** av)
{
    if (ac != 2)
        return error("Invalid number of argument");

    BitcoinExchange c;
    c.btc(std::string(av[1]));
    return 0;
}