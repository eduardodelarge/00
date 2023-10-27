/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caeduard <caeduard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 02:04:51 by caeduard          #+#    #+#             */
/*   Updated: 2023/10/27 03:52:31 by caeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int panic(std::string error_msg)
{
	std::cerr << error_msg << "\n";
	return EXIT_FAILURE;
}


float ft_stof(const std::string& str)
{
    float num;
    std::stringstream ss(str);

    ss >> num;
    return num;
}

BitcoinExchange::BitcoinExchange(void) {};

BitcoinExchange::BitcoinExchange(const BitcoinExchange& to_copy) {
    *this = to_copy;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& to_copy) {
    this->dataBase = to_copy.dataBase;
    return *this;
}

BitcoinExchange::~BitcoinExchange(void) {};

float BitcoinExchange::getRateFromDataBase(const std::string& date)
{
    if (this->dataBase.count(date) > 0)
        return this->dataBase.at(date);
    return (--this->dataBase.lower_bound(date))->second;
}

bool BitcoinExchange::isDateInCorrectFormat(const std::string& date)
{
    if (date.size() != 10)
    {
        std::cerr << "Error: incorrect date format => \"" << date << "\"" << std::endl;
        return false;
    }
    for (int i = 0; i < 10; i++)
    {
        if (i == 4 || i == 7)
        {
            if (date[i] != '-')
            {
                std::cerr << "Error: incorrect date format => \"" << date << "\"" << std::endl;
                return false;
            }
        }
        else if (!std::isdigit(date[i]))
        {
            std::cerr << "Error: incorrect date format => \"" << date << "\"" << std::endl;
            return false;
        }
    }
    return true;
}

bool BitcoinExchange::isValidDate(const std::string& date)
{
    int year, month, day;
    if (std::sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day) != 3)
    {
        std::cerr << "Error: incorrect date format => \"" << date << "\"" << std::endl;
        return false;
    }
    if (year < 2009 || year > 2022)
    {
        std::cerr << "Error: year is not in the database => \"" << date << "\"" << std::endl;
        return false;
    }
    if (month < 1 || month > 12)
    {
        std::cerr << "Error: incorrect month => \"" << date << "\"" << std::endl;
        return false;
    }
    if (day < 1 || day > 31)
    {
        std::cerr << "Error: incorrect day => \"" << date << "\"" << std::endl;
        return false;
    }
    if (day == 31 && (month == 2 || month == 4 || month == 6 || month == 9 || month == 11))
    {
        std::cerr << "Error: incorrect day for month => \"" << date << "\"" << std::endl;
        return false;
    }
    if (day > 28 && month == 2)
    {
        std::cerr << "Error: incorrect day for February => \"" << date << "\"" << std::endl;
        return false;
    }
    return true;
}

bool BitcoinExchange::isRateInCorrectFormat(const std::string& rate)
{
	if (rate.empty() || rate.find_first_not_of("0123456789.-") != std::string::npos
	||  rate.at(0) == '.' || rate.find('.', rate.length() - 1) != std::string::npos)
		std::cerr << "Error: invalid rate => " << "\"" << rate << "\"" << '\n';
	else if (rate.at(0) == '-')
		std::cerr << "Error: not a positive number." << '\n';
	else if (rate.length() > 10 || (rate.length() == 10 && rate > "2147483647"))
		std::cerr << "Error: too large a number." << '\n';
	else
		return true;
	return false;
}

void BitcoinExchange::readInternalDataBase(std::ifstream& internal_db)
{
    std::string line;
    std::getline(internal_db, line); // skip first line
    while (std::getline(internal_db, line))
    {
        size_t delim = line.find(',');
        if (delim == std::string::npos)
        {
            std::cerr << "Error: invalid line format => \"" << line << "\"" << std::endl;
            continue;
        }
        std::string date_str = line.substr(0, delim);
        std::string rate_str = line.substr(delim + 1);
        char* endptr;
        float rate = std::strtof(rate_str.c_str(), &endptr);
        if (*endptr != '\0')
        {
            std::cerr << "Error: invalid rate => \"" << line << "\"" << std::endl;
            continue;
        }
        this->dataBase[date_str] = rate;
    }
    internal_db.close();
}