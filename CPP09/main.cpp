/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuury <yuury@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 23:16:25 by yuury             #+#    #+#             */
/*   Updated: 2025/10/12 18:28:29 by yuury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

int error(std::string msg)
{
    std::cerr << "ERROR: "<< msg << std::endl;
    return 1;
}

int main(int ac, char** av)
{
    std::ifstream   db("data.csv");

    if (!db.is_open())
        return error("Data Base file can't be opened!");
    if (ac != 2)
        return error("Invalid number of arguments!");
    // bitcoinexchange::exchange(database file, input file);
    db.close();
}