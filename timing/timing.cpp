#ifndef __TIME_H__
#define __TIME_H__

#include <sys/time.h>
#include <stdlib.h>
#include <iostream>
#include <assert.h>


double wtime()
{
	double time[2];	
	struct timeval time1;
	gettimeofday(&time1, NULL);

	time[0]=time1.tv_sec;
	time[1]=time1.tv_usec;

	return time[0]+time[1]*1.0e-6;
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


	std::cout<<"Input format:/path/to/exe size(2^size as the real size of the array)\n";
	assert(args>=2);//Make sure we have at least 1 arguments in the input line;
	
	for(int i = 0; i < args; i++)
		std::cout<<"argv["<<i<<"]: "<<argv[i]<<"========== ";
	std::cout<<"\n";

	int size = 1<<atoi(argv[1]);
	
	//Allocate the space for this array
	int *array = new int[size];

	//Generate random numbers for this array
	for(int i = 0; i < size ; i++)
		array[i] = rand()%238448;

	//Pick the first generated number to search
	int search_key = array[0];

	
	//for (int i = 0; i < size; i ++)
	//	std::cout<<array[i]<<" ";
	//std::cout<<"\n";
	
	double time_begin = wtime();
	
	//for(int i = 0; i < (1<<20); i++)
	//	//binary search
	//	binary_search(array,rand()%238448, 0, size);
	
	// void qsort(void *base, size_t nmemb, size_t size,
	//                   int (*compar)(const void *, const void *));
	//sort the array
	qsort(array, size, sizeof(int), my_compare_func);
	
	//Insert the applications we want to measure the time consumption
	//...
	//Matrix multiplication
	//Qsort
	//Binary Search
	//Linear Search
	
	double my_time = wtime() - time_begin;

	//std::cout<<"The time consumption is: "<<(my_time)/(1<<20)<<" second(s).\n";
	std::cout<<"The time consumption is: "<<my_time<<" second(s).\n";
}
