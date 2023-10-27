/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caeduard <caeduard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 04:47:50 by caeduard          #+#    #+#             */
/*   Updated: 2023/10/27 05:13:38 by caeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(const std::string& expression) {
    std::istringstream input(expression);
    std::string token;

    while (input >> token) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            if (stack.size() < 2) {
                std::cerr << "Error: Not enough operands for operator " << token << std::endl;
                throw std::runtime_error("Not enough operands");
            }

            int operand2 = stack.top();
            stack.pop();
            int operand1 = stack.top();
            stack.pop();

            if (token == "+")
                stack.push(operand1 + operand2);
            else if (token == "-")
                stack.push(operand1 - operand2);
            else if (token == "*")
                stack.push(operand1 * operand2);
            else if (token == "/") {
                if (operand2 == 0) {
                    std::cerr << "Error: Division by zero" << std::endl;
                    throw std::runtime_error("Division by zero");
                }
                stack.push(operand1 / operand2);
            }
        } else {
            int operand;
            char* end;
            operand = std::strtol(token.c_str(), &end, 10);

            if (*end != '\0') {
                std::cerr << "Error: Invalid operand - " << token << std::endl;
                throw std::invalid_argument("Invalid operand");
            }

            stack.push(operand);
        }
    }
}

int RPN::evaluate() const {
    if (stack.size() == 1) {
        return stack.top();
    } else {
        std::cerr << "Error: Incomplete expression" << std::endl;
        throw std::runtime_error("Incomplete expression");
    }
}