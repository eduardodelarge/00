/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caeduard <caeduard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 06:39:46 by caeduard          #+#    #+#             */
/*   Updated: 2023/10/27 07:05:14 by caeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PEMERGEME_HPP
# define PEMERGEME_HPP

#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <time.h>
#include <sstream>

class PMergeMeDeque
{
public:
	int total_deque;

	PMergeMeDeque();
	~PMergeMeDeque();

	std::deque<int> deque;

	void	addDeque(char **argv, std::deque<int> *pdeque);
	void	printDeque(std::deque<int> &pdeque);
};

class PMergeMeVector
{
public:
	int total_vector;

	PMergeMeVector();
	~PMergeMeVector();

	std::vector<int> vector;

	void	addVector(char **argv, std::vector<int> *pvector);
	void	printVec(std::vector<int> &pvector);
};

#endif