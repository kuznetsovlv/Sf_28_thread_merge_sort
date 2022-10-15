#include <algorithm>
#include <future>
#include "merge_sort.h"

const size_t STOP_THREADING_AT = 10000;

void merge(int*, int*, int*);

void mergeSort(int *arr, const size_t size)
{
	mergeSort(arr, arr + size);
}

void mergeSort(int *beg, int *end)
{
	if(end - 1 <= beg)
	{
		return;
	}

	int *mid = beg + (end - beg) / 2;

	if(end - beg >= STOP_THREADING_AT)
	{
		auto f = std::async(std::launch::async,[beg, mid](){mergeSort(beg, mid);});
		mergeSort(mid, end);
		f.get();
	}
	else
	{
		mergeSort(beg, mid);
		mergeSort(mid, end);
	}

	merge(beg, mid, end);
}

void merge(int *beg, int *mid, int *end)
{
	const size_t size = end - beg;

	int *tmp = new int[size];

	int *first = beg, *second = mid;
	size_t i = 0;

	while(first < mid && second < end)
	{
		if(*first < *second)
		{
			*(tmp + i) = *first;
			++first;
		}
		else
		{
			*(tmp + i) = *second;
			++second;
		}
		++i;
	}

	while(first < mid)
	{
		*(tmp + i) = *first;
		++first;
		++i;
	}

	while(second < end)
	{
		*(tmp + i) = *second;
		++second;
		++i;
	}

	for(size_t i = 0; i < size; ++i)
	{
		*(beg + i) = *(tmp + i);
	}

	delete [] tmp;
}
