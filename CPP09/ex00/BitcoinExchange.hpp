/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuury <yuury@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 20:41:05 by ychagri           #+#    #+#             */
/*   Updated: 2025/10/24 18:43:10 by yuury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <map>
// #include <fstream>
#include <string>
#include <exception>
#include <iomanip>

#define DATABASE "data.csv"


class BitcoinExchange
{   
        std::map<std::string, double>    _db;

        // BitcoinExchange( void );
        BitcoinExchange( const BitcoinExchange &other );
        BitcoinExchange& operator=( const BitcoinExchange &other );
        
        void                             _extractDataBase( void );
        bool                            _dateParser(const std::string &date);
        std::map<std::string, float>&   _parseline(const std::string &line, char sep );
        static std::string              _trim(const std::string &s);
        void                            inputProcessing(const std::string &filName);
        void                            searchDatabase(const std::string &date, double value);
        // std::string[] ft_split( const std::string &line, char del);
        
    public:
        BitcoinExchange( void );
        ~BitcoinExchange( void );
        void btc( const std::string &inputfName );
    
};