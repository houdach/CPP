#include "BitcoinExchange.hpp"
#include <fstream>

 BitcoinExchange::BitcoinExchange()
{
   loadDatabase("data.csv");
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : database(other.database)
{}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
    {
        this->database = other.database;
    }
    return *this;
}
   

BitcoinExchange::~BitcoinExchange()
{};

void BitcoinExchange::loadDatabase(const std::string &filename)
{
    std::ifstream inputFile(filename);
    if (inputFile.is_open())
    {
        std::string line;
        std::string key;
        double value;
        std::getline(inputFile, line);
        while (std::getline(inputFile, line) )
        {
            size_t colonPos = line.find(',');
            if (colonPos != std::string::npos)
            {
                key = line.substr(0, colonPos);
                value = stod(line.substr(colonPos + 1));
                database[key] = value;
            }
        }
    } 
    else 
    {
        std::cerr << "Error: Unable to open file " << std::endl;
    }
}

void BitcoinExchange::processInput(const std::string &filename)
{
    std::ifstream inputFile(filename);
    if(inputFile.is_open())
    {
        std::string line;
      if (std::getline(inputFile, line)) 
        {
            if (line != "date | value")
                processLine(line);
        }
        while(std::getline(inputFile, line))
        {
            processLine(line);
        }
    }
     else 
    {
        std::cerr << "Error: Unable to open file " << std::endl;
    }
}

void BitcoinExchange::processLine(const std::string &line)
{
    size_t sep = line.find('|');
    double value;
    if (sep == std::string::npos) 
    {
        std::cerr << "Error: bad input => " << line << std::endl;
        return;
    }
    std::string date = trim(line.substr(0, sep));
    std::string valueStr = trim(line.substr(sep + 1));
    if(!isValidDate(date))
    {
        std::cerr << "Error: bad input => " << line << std::endl;
        return;
    }
    if(!isValidValue(valueStr, value))
    {
        return;
    }
    double rate = getExchangeRate(date);
    printResult(date, value, rate);
}

bool BitcoinExchange::isValidValue(const std::string &valueStr, double &value)const
{
    int dotCount = 0;
    for (size_t i = 0; i < valueStr.size(); ++i)
    {
        char c = valueStr[i];
        if (c == '.')
        {
            dotCount++;
            if (dotCount > 1)
                return false;
        }
        else if (c == '-')
        {
            if (i != 0)
                return false;
        }
        else if (!std::isdigit(c) && c != ' ')
        {
            return false;
        }
    }
    value = std::stod(valueStr);
    if (value < 0)
    {
        std::cerr << "Error: not a positive number." << std::endl;
        return false;
    }
    if (value > 1000)
    {
        std::cerr << "Error: too large a number." << std::endl;
        return false;
    }

    return true;
}

bool BitcoinExchange::isValidDate(const std::string &date) const
{
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    int year, month, day;
    try {
        year  = std::stoi(date.substr(0, 4));
        month = std::stoi(date.substr(5, 2));
        day   = std::stoi(date.substr(8, 2));
    }
    catch (...) {
        return false;
    }

    if (month < 1 || month > 12)
        return false;

    int daysInMonth[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

    if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
        daysInMonth[1] = 29;

    if (day < 1 || day > daysInMonth[month - 1])
        return false;

    return true;
}


double BitcoinExchange::getExchangeRate(const std::string &date) const
{
     std::map<std::string, double>::const_iterator it = database.lower_bound(date);
    if (it != database.end() && it->first == date)
        return it->second;
    if (it == database.begin())
    {
        std::cerr << "Error: no earlier date found for => " << date << std::endl;
        return 0.0;
    }
    --it;
    return it->second;
}

void BitcoinExchange::printResult(const std::string &date, double value, double rate) const
{
    std::cout << date << " => " << value << " = " << value * rate <<std::endl;
}

static std::string trim(const std::string& str)
{
    size_t start = str.find_first_not_of(" \t\n\r");
    if (start == std::string::npos)
        return "";

    size_t end = str.find_last_not_of(" \t\n\r");
    return str.substr(start, end - start + 1);
}