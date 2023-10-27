/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caeduard <caeduard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 04:47:47 by caeduard          #+#    #+#             */
/*   Updated: 2023/10/27 05:07:27 by caeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <stdexcept>
#include <stack>

class RPN {
public:
    RPN(const std::string& expression);
    int evaluate() const;

private:
    std::stack<int> stack;
};

#endif // RPN_HPP