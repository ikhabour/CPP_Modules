#pragma once

#include <iostream>
#include <algorithm>
#include <fstream>
#include <map>

class BitcoinExchange
{
    private:
        std::map<std::string, float> map;
        std::ifstream inputFile;
        std::ifstream dataFile;
    private:
        void    readDB();
        void    handleFiles();
        int     headError(std::string& line);
        void    handleLine(std::string& line);
        int     checkDateValue(std::string& date, std::string& value);
        float   getRate(std::string& date);
        int     checkDate(std::string& date);
    public:
        BitcoinExchange();
        BitcoinExchange(const char* filename);
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        ~BitcoinExchange();
};