#ifndef __TIME_H__
#define __TIME_H__

#include <sys/time.h>
#include <stdlib.h>
#include <iostream>
#include <assert.h>
#include <ctime>
#include <chrono>

int normal_search(int *array, int search_key, int beg, int end) {
        for (int i = beg; i < end; i ++) {
                if (array[i] == search_key) {
                        return i;
                }
        }
        return -1;
}

void bubble_sort(int *array, int beg, int end) {
	for (int i = beg; i < end; i ++) {
		for (int j = i+1; j < end; j ++) {
			if(array[i] > array[j]) {
				int tmp = array[j];
				array[j] = array[i];
				array[i] = tmp;	
			}	
		}
	}
}

double wtime()
{
	double time[2];	
	struct timeval time1;
	gettimeofday(&time1, NULL);

	time[0]=time1.tv_sec;
	time[1]=time1.tv_usec;

	return time[0]*1.0e6 + time[1];
}

#endif

int my_compare_func (const void * a, const void * b)
{
	  return ( *(int*)a - *(int*)b );
}

int binary_search(int *array, int search_key, int beg, int end)
{
	
	while(beg<=end)
	{
		int mid = (beg + end)/2;
		if(array[mid] == search_key)
		{
//			printf("Found %d at index = %d\n",search_key,mid);
			return 1;
		}else if(array[mid] < search_key){
			beg = mid + 1;

		}else{
			end = mid - 1;
		}
		//searching range changed to
//		printf("Valid range: array[%d] = %d -- array[%d] = %d for search_key = %d.\n", beg,array[beg],end,array[end-1], search_key);
	}
	
//	printf("Didn't find %d in this array\n", search_key);
	return -1;
}

int main(int args, char **argv){


	std::cout<<"Input size  of the array\n";
	
	int size=0; 

	std::cin >> size;

	// Allocate the space for this array
	int *array = new int[size];

	// Generate random numbers for this array
	for(int i = 0; i < size ; i++)
		array[i] = rand()%238448;

	// Pick the first generated number to search
	int search_key = array[0];
	
	double time_begin = wtime();
	std::clock_t c_start = std::clock();

	qsort(array, size, sizeof(int), my_compare_func);
	// bubble_sort(array, 0, size);

	// binary_search(array, search_key, 0, size);

	// normal_search(array, search_key, 0, size);

	// Insert the applications we want to measure the time consumption
	// ...
	// Matrix multiplication
	// Qsort
	// Binary Search
	// Linear Search
	
	double my_time = wtime() - time_begin;
	std::clock_t c_end = std::clock();

	std::cout << "The time consumption is: " << my_time << " (us).\n";
	long double time_elapsed_ms = 1000000.0 * (c_end-c_start) / CLOCKS_PER_SEC;
	std::cout << "The CPU time used: " << time_elapsed_ms << " (us).\n";

}

