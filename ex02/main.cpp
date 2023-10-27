/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caeduard <caeduard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 06:40:34 by caeduard          #+#    #+#             */
/*   Updated: 2023/10/27 07:20:04 by caeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void merge_deque(std::deque<int> &pdeque, int left, int mid, int right)
{
	int n1 = mid - left + 1; 
	int n2 = right - mid; 
	int tempL[n1];
	int tempR[n2];

	for (int i = 0; i < n1; i++)
		tempL[i] = pdeque[left + i];
	for (int j = 0; j < n2; j++)
		tempR[j] = pdeque[mid + j + 1];

	int i = 0;
	int j = 0;
	int k = left;

	while (i < n1 && j < n2) 
	{
		if (tempL[i] <= tempR[j])
		{
			pdeque[k] = tempL[i];
			i++;
		}
		else
		{
			pdeque[k] = tempR[j];
			j++;
		}
		k++;
	}

	while (i < n1) 
	{
		pdeque[k] = tempL[i];
		i++;
		k++;
	}

	while (j < n2) 
	{
		pdeque[k] = tempR[j];
		j++;
		k++;
	}
}

void	merge_vec(std::vector<int> &pvec, int left, int mid, int right)
{
	int n1 = mid - left + 1; 
	int n2 = right - mid; 
	int tempL[n1];
	int tempR[n2];

	for (int i = 0; i < n1; i++)
		tempL[i] = pvec[left + i];
	for (int j = 0; j < n2; j++)
		tempR[j] = pvec[mid + j + 1];

	int i = 0;
	int j = 0;
	int k = left;

	while (i < n1 && j < n2) 
	{
		if (tempL[i] <= tempR[j])
		{
			pvec[k] = tempL[i];
			i++;
		}
		else
		{
			pvec[k] = tempR[j];
			j++;
		}
		k++;
	}

	while (i < n1) 
	{
		pvec[k] = tempL[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		pvec[k] = tempR[j];
		j++;
		k++;
	}
}

void	mergesortDeque(std::deque<int> &pdeque, int left, int right)
{
	if (left >= right)
		return;
	int	mid = left + (right - left) / 2;
	mergesortDeque(pdeque, left, mid);
	mergesortDeque(pdeque, mid + 1, right);
	merge_deque(pdeque, left, mid, right);
}

void	mergesortVec(std::vector<int> &pvector, int left, int right)
{
	if (left >= right)
		return;
	int	mid = left + (right - left) / 2;
	mergesortVec(pvector, left, mid);
	mergesortVec(pvector, mid + 1, right);
	merge_vec(pvector, left, mid , right);
}

template <typename T>
T	add(int left, int right)
{
	return (left + right);
}

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Arg Error" << std::endl;
		return (1);
	}

	int i = 1;
	int j = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] < 48 || argv[i][j] > 57)
			{
				std::cerr << "You should enter Just number" << std::endl;
				return (1);
			}
			j++;
		}
		i++;
	}

	clock_t t1 = clock();
	PMergeMeVector obj1;

	obj1.addVector(&argv[1], &obj1.vector);
	std::cout << "Before:	"; obj1.printVec(obj1.vector);
	mergesortVec(obj1.vector, 0, obj1.total_vector - 1);
	std::cout << "After:	"; obj1.printVec(obj1.vector);
	clock_t t2 = clock();
	double	time_1 = double(t2 - t1);
	std::cout << "Time to process a range of " << obj1.total_vector << " elements with std::vector : " << std::fixed << time_1 << " us" << std::endl;

	std::cout << "--------------------------" << std::endl;

	clock_t t3 = clock();
	PMergeMeDeque obj2;
	obj2.addDeque(&argv[1], &obj2.deque);
	mergesortDeque(obj2.deque, 0, obj2.total_deque - 1);
	clock_t t4 = clock();
	double	time_2 = double(t4 - t3);

	std::cout << "Time to process a range of " << obj2.total_deque << " elements with std::deque : " << std::fixed << time_2 << " us" << std::endl;

	return(0);
}