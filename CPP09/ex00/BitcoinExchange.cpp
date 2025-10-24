/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuury <yuury@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 01:04:23 by yuury             #+#    #+#             */
/*   Updated: 2025/10/24 19:50:04 by yuury            ###   ########.fr       */
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
    this->_db.clear();
}


std::string
BitcoinExchange::_trim(const std::string& s) {
    size_t start = 0;
    size_t end = s.size();

    while (start < end && std::isspace(s[start]))
        ++start;

    while (end > start && std::isspace(s[end - 1]))
        --end;

    return s.substr(start, end - start);
}

bool    
BitcoinExchange::_dateParser(const std::string &date)
{
    std::string date2 = _trim(date);
    size_t         pos = date.find('-');
    if (pos == std::string::npos || date.length() != 6 + pos || date[pos + 3] != '-')
        return false; 

    std::stringstream ss(date);
    int year, mon, day;
    char dash1, dash2;

    if (!(ss >> year >> dash1 >> mon >> dash2 >> day))
        return false; 

    if (!ss.eof())
        return false;

    if (year < 0  || year > 2025 || mon < 1 || mon > 12 || day < 1 || day > 31)
        return false;
    
    int monthdays;
    switch (mon)
    {
        case 1: case  3: case  5: case 7: case  8: case 10: case 12:
            monthdays = 31;
            break;
        case 4: case 6: case 9 :case 11:
            monthdays = 30;
            break;
        case 2:
        {
            monthdays = 28;
            if (year % 4 == 0 || (year % 100 == 0 && year % 400 == 0))
                monthdays++;
            break;
        }
        
        default:
            return false;
    }
    return true;
}

double to_float(const std::string &value)
{
    std::stringstream ss(value);
    
    double i;

    if (!(ss >> i) || !ss.eof())
        return -1;
    
    return i;
}

void
BitcoinExchange::searchDatabase(const std::string &date, double value)
{
    std::map<std::string, double>::const_iterator it = this->_db.find(date);

    if (it == this->_db.end())
    {
        it = this->_db.upper_bound(date);
        if (it == this->_db.begin())
        {
            std::cerr << "Error: date too early" << std::endl;
            return ;
        }
        it--;
    }
    std::cout << date << " => " << value << " => " << value * it->second << std::endl; 
    
}


void
BitcoinExchange::_extractDataBase( void )
{
    std::ifstream dataBase(DATABASE);

    if (dataBase.is_open() == false)
        throw "Data base file Can't be read!";
    
    std::string line;
    std::string date;
    std::string val;

    if (!std::getline(dataBase, line))
        throw "Data base file is empty!";
    while(std::getline(dataBase, line))
    {
        size_t pos = line.find(',');
        date = line.substr(0, pos);
        val = line.substr(pos + 1);
        double value = to_float(val);
        this->_db[date] = value;
    }
}

void
BitcoinExchange::inputProcessing(const std::string &filName)
{
    std::ifstream input(filName.c_str());

    if (!input.is_open())
        throw "Input file can't be opened!";
    std::string line;
    if (!std::getline(input, line) || line != "date | value")
        throw "Invalid/Empty input file!";

    std::string date;
    std::string val;
    double value;
    while (std::getline(input, line))
    {
        line = _trim(line);
        size_t pos = line.find(" | ");
        if (pos == std::string::npos)
        {
            std::cerr << "Error: bad line format!" << std::endl;
            continue;
        }
        date = line.substr(0, pos);
        val = line.substr(pos + 3);
        value = to_float(val);
        if (!_dateParser(date) || (value < 0 || value > 1000))
        {
            std::cerr << "Error: invalid date/value!" << std::endl;
            continue;
        }
        searchDatabase(date, value);   
    }

    
}

void
BitcoinExchange::btc(const std::string &inputfName )
{
    try
    {
        _extractDataBase();
        inputProcessing(inputfName); 
    }
    catch(const char *msg)
    {
        std::cerr << msg << '\n';
    }

}
