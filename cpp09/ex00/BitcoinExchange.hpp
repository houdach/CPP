#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <map>

class BitcoinExchange
{
private:
    std::map<std::string, double> database;
    void processLine(const std::string &line);
    bool isValidDate(const std::string &date) const;
    bool isValidValue(const std::string &valueStr, double &value) const;
    double getExchangeRate(const std::string &date) const;
    void printResult(const std::string &date, double value, double rate) const;

public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);
    ~BitcoinExchange();

    void loadDatabase(const std::string &filename);
    void processInput(const std::string &filename);

};
#endif
