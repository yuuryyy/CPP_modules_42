/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuury <yuury@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 01:04:23 by yuury             #+#    #+#             */
/*   Updated: 2025/10/17 19:27:03 by yuury            ###   ########.fr       */
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

BitcoinExchange::~BitcoinExchange(void){}

void
BitcoinExchange::btc(std::ifstream dataBase, std::string inputfName )
{
    
}
