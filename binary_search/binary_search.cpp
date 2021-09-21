#include <iostream>
#include <stdlib.h>
#include <assert.h>

int my_compare_func (const void * a, const void * b)
{
	  return ( *(int*)a - *(int*)b );
}

int main (int args, char **argv)
{
	std::cout<<"Input format:/path/to/exe size\n";
	assert(args>=2);//Make sure we have at least 1 arguments in the input line;

	int size = atoi(argv[1]);

	//
	//Allocate the space for this array
	int *array = new int[size];

	//Generate random numbers for this array
	for(int i = 0; i < size ; i++)
		array[i] = rand()%238448;

	// void qsort(void *base, size_t nmemb, size_t size,
	//                   int (*compar)(const void *, const void *));
	//sort the array
	qsort(array, size, sizeof(int), my_compare_func);
	
	for (int i = 0; i < size; i ++)
		std::cout<<array[i]<<" ";
	std::cout<<"\n";
	//binary search
}
