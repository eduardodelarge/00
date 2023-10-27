/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caeduard <caeduard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 02:04:58 by caeduard          #+#    #+#             */
/*   Updated: 2023/10/27 06:26:24 by caeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		throw std::invalid_argument("Error: invalid number of arguments.");

	std::ifstream input_db(argv[1], std::ifstream::in);
	if (!input_db.is_open())
		throw std::invalid_argument("Error: could not open file");

    std::ifstream internal_db("./data.csv", std::ifstream::in);
	if (!internal_db.is_open())
		throw std::invalid_argument("Error: fatal: could not open internal database file");

	BitcoinExchange btc;
	btc.readInternalDataBase(internal_db);

	std::string line;

    // skip first line
    std::getline(input_db, line);
    while (std::getline(input_db, line))
    {
        size_t delim = line.find('|');
		if (delim == std::string::npos
		||	line.length() < delim + 2)
		{
			std::cerr << "Error: bad input => " << "\"" << line << "\"" << '\n';
			continue ;
		}

		std::string date = line.substr(0, delim - 1);
		if (!btc.isDateInCorrectFormat(date) || !btc.isValidDate(date))
			continue;

        std::string rate_as_str = line.substr(delim + 2);
		if (!btc.isRateInCorrectFormat(rate_as_str))
			continue;
		float rate = ft_stof(rate_as_str);

		std::cout << date << " => " << rate << " = " << std::fixed << std::setprecision(2) << rate * btc.getRateFromDataBase(date) << std::endl;
    }
    input_db.close();
    internal_db.close();
	return 0;
}