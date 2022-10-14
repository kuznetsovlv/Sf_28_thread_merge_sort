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
	if(end <= beg)
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
	while(*beg < *mid)
	{
		++beg;
	}

	int *current = mid;

	while(current < end || mid < end)
	{
		if(beg == current)
		{
			break;
		}

		if(*mid < *current)
		{
			if(*mid < *beg)
			{
				std::swap(*beg, *mid);
			}
			++beg;
			if(beg == mid)
			{
				++mid;
			}
		}
		else if(current < end)
		{
			if(*current < *beg)
			{
				std::swap(*beg, *current);
				++current;
			}
			++beg;
		}
	}
}
