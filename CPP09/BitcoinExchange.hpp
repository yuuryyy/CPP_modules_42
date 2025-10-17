/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychagri <ychagri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 20:41:05 by ychagri           #+#    #+#             */
/*   Updated: 2025/10/17 20:41:30 by ychagri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <fstream>
// #include <sstream>
#include <algorithm>
#include <map>
#include <exception>


class BitcoinExchange
{   
        std::map<std::string, float>    _db;

        BitcoinExchange( void );
        // BitcoinExchange( void );
        BitcoinExchange( const BitcoinExchange &other );
        BitcoinExchange& operator=( const BitcoinExchange &other );
        ~BitcoinExchange( void );

        void    extractDataBase(const std::ifstream &dataBase);
        
    public:
        static void btc(const std::ifstream &dataBase, const std::string &inputfName );
    
}