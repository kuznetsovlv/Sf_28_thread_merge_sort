#include <iostream>
#include <ctime>
#include <random>
#include <string>
#include "merge_sort.h"

const size_t SIZE = 100000;
const int LIMIT = 10000;

void print(const int*, const size_t);

int main(int argc, char **argvs)
{
	srand(time(nullptr));

	const size_t size = argc > 1 ? std::stoull(*(argvs + 1)) : SIZE;

	int *arr = new int[size];

	for(size_t i = 0; i < size; ++i)
	{
		*(arr + i) = rand() % LIMIT;
	}

	std::cout << "Before sort:" << std::endl;
	print(arr, size);

	mergeSort(arr, size);

	std::cout << "After sort:" << std::endl;
	print(arr, size);

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
