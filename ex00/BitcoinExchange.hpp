/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caeduard <caeduard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 02:04:54 by caeduard          #+#    #+#             */
/*   Updated: 2023/10/27 04:44:18 by caeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <map>

class BitcoinExchange {
    public:
        BitcoinExchange(void);
        BitcoinExchange(const BitcoinExchange& to_copy);
        BitcoinExchange& operator=(const BitcoinExchange& to_copy);
        ~BitcoinExchange(void);

        void readInternalDataBase(std::ifstream& internal_db);

        float getRateFromDataBase(const std::string& date);

        bool isDateInCorrectFormat(const std::string &date);
        bool isValidDate(const std::string& date);
        bool isRateInCorrectFormat(const std::string& rate);

    private:
        std::map<std::string, float> dataBase;
};
    float ft_stof(const std::string& str);
    int panic(std::string error_msg);

#endif