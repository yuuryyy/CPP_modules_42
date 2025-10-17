#pragma once

#include <iostream>
#include <fstream>
// #include <sstream>
#include <algorithm>
#include <map>


class BitcoinExchange
{
    
    
        std::map<std::string, float>    _db;

        BitcoinExchange( void );
        // BitcoinExchange( void );
        BitcoinExchange( const BitcoinExchange &other );
        BitcoinExchange& operator=( const BitcoinExchange &other );
        ~BitcoinExchange( void );
        
    public:
        static void btc(std::ifstream dataBase, std::string inputfName );
    
}