#include <iostream>
#include <stdlib.h>
#include <assert.h>

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
			printf("Found %d at index = %d\n",search_key,mid);
			return 1;
		}else if(array[mid] < search_key){
			beg = mid + 1;

		}else{
			end = mid - 1;
		}
		//searching range changed to
		printf("Valid range: array[%d] = %d -- array[%d] = %d for search_key = %d.\n", beg,array[beg],end,array[end-1], search_key);
	}
	
	printf("Didn't find %d in this array\n", search_key);
	return -1;
}

int main (int args, char **argv)
{
	std::cout<<"Input format:/path/to/exe size\n";
	assert(args>=2);//Make sure we have at least 1 arguments in the input line;
	
	for(int i = 0; i < args; i++)
		std::cout<<"argv["<<i<<"]: "<<argv[i]<<"========== ";
	std::cout<<"\n";

	int size = atoi(argv[1]);

	//
	//Allocate the space for this array
	int *array = new int[size];

	//Generate random numbers for this array
	for(int i = 0; i < size ; i++)
		array[i] = rand()%238448;

	//Pick the first generated number to search
	int search_key = array[0];

	// void qsort(void *base, size_t nmemb, size_t size,
	//                   int (*compar)(const void *, const void *));
	//sort the array
	qsort(array, size, sizeof(int), my_compare_func);
	
	//for (int i = 0; i < size; i ++)
	//	std::cout<<array[i]<<" ";
	//std::cout<<"\n";
	
	//binary search
	binary_search(array, search_key, 0, size);
	
	return 0;	
}
