/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuury <yuury@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 23:16:25 by yuury             #+#    #+#             */
/*   Updated: 2025/10/24 19:03:16 by yuury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "BitcoinExchange.hpp"

int error(std::string msg)
{
    std::cerr << "ERROR: "<< msg << std::endl;
    return 1;
}

int main(int ac, char** av)
{
    if (ac != 2)
        return error("Invalid number of argument");

    BitcoinExchange c;
    c.btc(std::string(av[1]));
}