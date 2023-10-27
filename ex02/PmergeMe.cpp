/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caeduard <caeduard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 06:39:54 by caeduard          #+#    #+#             */
/*   Updated: 2023/10/27 07:03:46 by caeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PMergeMeVector::PMergeMeVector()
{
	this->total_vector = 0;
}

PMergeMeVector::~PMergeMeVector() {}

PMergeMeDeque::PMergeMeDeque()
{
	this->total_deque = 0;
}

PMergeMeDeque::~PMergeMeDeque() {}

void PMergeMeVector::addVector(char **argv, std::vector<int> *pvector)
{
    int i = 0;
    while (argv[i])
    {
        std::istringstream iss(argv[i]);
        int value;
        if (!(iss >> value))
        {
            std::cerr << "Error: Invalid argument - " << argv[i] << std::endl;
            throw std::invalid_argument("Invalid argument");
        }
        pvector->push_back(value);
        this->total_vector++;
        i++;
    }
}

void PMergeMeDeque::addDeque(char **argv, std::deque<int> *pdeque)
{
    int i = 0;
    while (argv[i])
    {
        std::istringstream iss(argv[i]);
        int value;
        if (!(iss >> value))
        {
            std::cerr << "Error: Invalid argument - " << argv[i] << std::endl;
            throw std::invalid_argument("Invalid argument");
        }
        pdeque->push_back(value);
        this->total_deque++;
        i++;
    }
}

void	PMergeMeDeque::printDeque(std::deque<int> &pdeque)
{
	std::deque<int>::iterator it;

	it = pdeque.begin();
	while (it != pdeque.end())
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::cout << std::endl;
}

void	PMergeMeVector::printVec(std::vector<int> &pvector)
{
	std::vector<int>::iterator it;

	it = pvector.begin();
	while (it != pvector.end())
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
}