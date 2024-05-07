#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(char const* filename)
{
    this->dataFile.open("data.csv");
    if (!this->dataFile.is_open() || !this->dataFile.good())
    {
        std::cerr<<"Failed to open data.csv file"<<std::endl;
        exit(1);
    }
    this->inputFile.open(filename);
    if (!this->inputFile.is_open() || !this->inputFile.good())
    {
        std::cerr<<"Failed to open input.txt file"<<std::endl;
        exit(1);
    }
    handleFiles();
}

int     BitcoinExchange::headError(std::string& line)
{
    if (line != "date | value")
    {
        std::cerr<<"the first line of the file should contain : \"date | value\""<<std::endl;
        return 1;
    }
    return 0;
}

float   BitcoinExchange::getRate(std::string& date)
{
    // calcuations done assuming the map container is date sorted
    std::map<std::string , float>::iterator it = this->map.lower_bound(date);
    if (it == this->map.begin() && date < it->first) // date given is less than any date
        return (it->second);
    else if (it == this->map.end()) // date given greater than anydate
        it--;
    else if (it->first != date) // date not found return the closest lower date
        it--;
    // otherwise the date is found
    return (it->second);
}

bool isLeapYear(int year) {
    // If the year is evenly divisible by 4
    if (year % 4 == 0) {
        // If it's divisible by 100, check if it's also divisible by 400
        if (year % 100 == 0) {
            return year % 400 == 0;
        } else {
            return true;
        }
    } else {
        return false;
    }
}

int     BitcoinExchange::checkDate(std::string& date)
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return 0;
    int day = atoi(date.substr(8, 2).c_str());
    int month = atoi(date.substr(5, 2).c_str());
    int year = atoi(date.substr(0, 4).c_str());
    if (day < 1 || day > 31 || month < 1 || month > 12 || year < 0)
        return 0;
    if (month % 2 == 0 && day > 30 && month != 2)
        return 0;
    if (month == 2 && !isLeapYear(year) && day > 28)
        return 0;
    return 1;
}

int isNumeric(std::string& str)
{
    char c;
    int start = 0;
    if (str[0] == '-' || str[0] == '+')
        start++;
    int point = 0;
    for (size_t i = start; i < str.length(); i++)
    {
        c = str[i];
        if (!isdigit(c))
        {
            if (c == '.' && i != 0 && !point)
                point = 1;
            else
                return (0);
        }
    }
    return (1);
}

int     BitcoinExchange::checkDateValue(std::string& date, std::string& value)
{
    int err = checkDate(date);
    if (date.empty() || value.empty() || !err || !isNumeric(value))
    {
        std::cerr<<"Error : bad input => " << date << " | " <<value<<std::endl;
        return 0;
    } 
    float val = std::atof(value.c_str());
    if (val < 0)
    {
        std::cerr<<"Error : not a positive number." << std::endl;
        return 0;
    }
    if (val > 1000)
    {
        std::cerr<<"Error : too large a number." << std::endl;
        return 0;
    }
    return 1;
}

void    BitcoinExchange::handleLine(std::string& line)
{
    std::string to_find(" | ");
    if (line.empty())
    {
        std::cerr<<"Line is empty."<<std::endl;
        return ;
    }
    size_t index = line.find(to_find);
    if (index == std::string::npos)
    {
        std::cerr<<"Error: bad input => "<<line<<std::endl;
        return ;
    }
    std::string date = line.substr(0, index);
    std::string value = line.substr(index + 3, line.length());
    if (!checkDateValue(date, value))
        return ;
    std::cout<<date<<" => ";
    std::cout<<value<<" = ";
    std::cout<<getRate(date) * std::atof(value.c_str())<<std::endl;
}

void    BitcoinExchange::handleFiles()
{
    readDB();
    std::string line;
    if (!std::getline(this->inputFile, line))
    {
        std::cerr<<"Error : File is empty"<<std::endl;
        exit(1);
    }
    if (headError(line))
        return ;
    while (std::getline(this->inputFile, line))
        handleLine(line);
}

void    BitcoinExchange::readDB()
{
    std::string line;
    std::string key, value;


    if (!std::getline(this->dataFile, line))
    {
        std::cerr<<"Error : Data File is empty"<<std::endl;
        exit(1);
    }
    while (std::getline(this->dataFile, line))
    {
        key = line.substr(0, 10);
        value = line.substr(11, line.length());
        map[key] = std::atof(value.c_str());
    }
}

BitcoinExchange::~BitcoinExchange()
{
    this->inputFile.close();
    this->dataFile.close();
}