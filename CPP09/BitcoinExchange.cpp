/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychagri <ychagri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 01:04:23 by yuury             #+#    #+#             */
/*   Updated: 2025/10/17 20:51:10 by ychagri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange( void) {}

BitcoinExchange::BitcoinExchange( const BitcoinExchange &other )
{
    *this = other;
}

BitcoinExchange& BitcoinExchange::operator=( const BitcoinExchange &other )
{
    if (this != &other)
        this->_db = other._db;
    return *this;
}

BitcoinExchange::~BitcoinExchange(void)
{
    // this->_db
}


void
BitcoinExchange::extractDataBase(const std::ifstream &dataBase)
{
    if (dataBase.)
}

void
BitcoinExchange::btc(const std::ifstream &dataBase, const std::string &inputfName )
{
    //parse db file
}
