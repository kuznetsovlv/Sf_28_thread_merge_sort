#include <iostream>
#include <ctime>
#include <random>
#include "merge_sort.h"

const size_t SIZE = 10;

void print(const int*, const size_t);

int main()
{
	srand(time(nullptr));

	int *arr = new int[SIZE];

	for(size_t i = 0; i < SIZE; ++i)
	{
		*(arr + i) = rand() % 100;
	}

	std::cout << "Before sort:" << std::endl;
	print(arr, SIZE);

	mergeSort(arr, SIZE);

	std::cout << "After sort:" << std::endl;
	print(arr, SIZE);

	delete [] arr;

	return 0;
}

void print(const int* arr, const size_t size)
{
	for(size_t i = 0; i < size; ++i)
	{
		if(i)
		{
			std::cout << "\t";
		}
		std::cout << *(arr + i);
	}

	std::cout << std::endl;
}
