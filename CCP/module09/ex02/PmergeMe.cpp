/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:19:33 by dvandenb          #+#    #+#             */
/*   Updated: 2024/01/23 15:57:06 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void PmergeMe::merge(std::vector<int> &arr, size_t left, size_t mid, size_t right)
{
	std::vector<int> arr_l(mid - left + 1);
	std::vector<int> arr_r(right - mid);

	for (size_t i = 0; i < arr_l.size(); i++)
		arr_l[i] = arr[left + i];
	for (size_t i = 0; i < arr_r.size(); i++)
		arr_r[i] = arr[mid + i + 1];
	size_t i = 0;
	size_t j = 0;
	size_t k = left;
	while (i < arr_l.size() && j < arr_r.size())
	{
		if (arr_l[i] <= arr_r[j])
			arr[k++] = arr_l[i++];
		else
			arr[k++] = arr_r[j++];
	}
	while (i < arr_l.size())
		arr[k++] = arr_l[i++];
	while (j < arr_r.size())
		arr[k++] = arr_r[j++];
}

void PmergeMe::merge_sort(std::vector<int> &arr, size_t left, size_t right)
{
	if (left >= right)
		return ;
	size_t mid = left + ((right - left) / 2);
	merge_sort(arr, left, mid);
	merge_sort(arr, mid + 1, right);
	merge(arr, left, mid, right);
}

void PmergeMe::merge(std::deque<int> &arr, size_t left, size_t mid, size_t right)
{
	std::deque<int> arr_l(mid - left + 1);
	std::deque<int> arr_r(right - mid);

	for (size_t i = 0; i < arr_l.size(); i++)
		arr_l[i] = arr[left + i];
	for (size_t i = 0; i < arr_r.size(); i++)
		arr_r[i] = arr[mid + i + 1];
	size_t i = 0;
	size_t j = 0;
	size_t k = left;
	while (i < arr_l.size() && j < arr_r.size())
	{
		if (arr_l[i] <= arr_r[j])
			arr[k++] = arr_l[i++];
		else
			arr[k++] = arr_r[j++];
	}
	while (i < arr_l.size())
		arr[k++] = arr_l[i++];
	while (j < arr_r.size())
		arr[k++] = arr_r[j++];
}

void PmergeMe::merge_sort(std::deque<int> &arr, size_t left, size_t right)
{
	if (left >= right)
		return ;
	size_t mid = left + ((right - left) / 2);
	merge_sort(arr, left, mid);
	merge_sort(arr, mid + 1, right);
	merge(arr, left, mid, right);
}
