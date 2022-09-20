#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <ctime>
#include <chrono>

#define print_out 0
#define num_search 1000000

int my_compare_func (const void * a, const void * b)
{
	  return ( *(int*)a - *(int*)b );
}

int normal_search(int *array, int search_key, int beg, int end) {
	for (int i = beg; i < end; i ++) {
		if (array[i] == search_key) {
			if (print_out) {
				printf("Found %d at index = %d\n",search_key, i);
			}
			// printf("Found %d at index = %d\n", search_key, i);
			return i;
		}
	}
	return -1;
}

int binary_search(int *array, int search_key, int beg, int end)
{
	
	while(beg<=end)
	{
		// (3) Try to inplement the binary search mid = (the upper bound + lower bound )/ 2
		int mid = beg;

		// End of the inplementing

		if(array[mid] == search_key)
		{
			if (print_out) {
				printf("Found %d at index = %d\n",search_key,mid);
			}
			return 1;
		}else if(array[mid] < search_key){
			beg = mid + 1;

		}else{
			end = mid - 1;
		}
		//searching range changed to
		if (print_out) {
			printf("Valid range: array[%d] = %d -- array[%d] = %d for search_key = %d.\n", beg,array[beg],end,array[end-1], search_key);
		}
	}
	
	printf("Didn't find %d in this array\n", search_key);
	return -1;
}

int main (int args, char **argv)
{
	// std::cout<<"Input format:/path/to/exe size numberOfSearch \n";

	// assert(args>=2);//Make sure we have at least 1 arguments in the input line;
	
	// for(int i = 0; i < args; i++)
	// 	std::cout<<"argv["<<i<<"]: "<<argv[i]<<"========== ";
	std::cout<<"\n";

	int size, search_num;
	// int size = atoi(argv[1]);
 	// int search_num = atoi(argv[2]);	
	std::cout<<"Input the Array Size and Search_Num:" << std::endl;
	std::cin >> size >> search_num;
	//
	//Allocate the space for this array
	int *array = new int[size];

	//Generate random numbers for this array
	
	// initial the random seed
	srand (time(NULL));

	// Generate random number.
	for(int i = 0; i < size ; i++)
		array[i] = rand()%147483647;

	//Pick the first generated number to search
	
	int search_key = array[rand()%size];

	auto start0 = std::chrono::high_resolution_clock::now();

	for (int j = 0; j < search_num; j ++) {	
		// (1) Please assign the randon value here:

		// End of the random value assignment
		normal_search(array, search_key, 0, size);
	}
	auto start = std::chrono::high_resolution_clock::now();
	// void qsort(void *base, size_t nmemb, size_t size,
	//                   int (*compar)(const void *, const void *));
	//sort the array
	
	qsort(array, size, sizeof(int), my_compare_func);
	
	auto end = std::chrono::high_resolution_clock::now();
	
	//for (int i = 0; i < size; i ++)
	//	std::cout<<array[i]<<" ";
	//std::cout<<"\n";
	
	//binary search
	for (int j = 0; j < search_num; j ++) {	
		// (2) Please assign the randon value here:

		// End of the random value assignment
		binary_search(array, search_key, 0, size);
	}
	auto end2 = std::chrono::high_resolution_clock::now();

	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

	auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>(end2 - end);
 
	auto duration3 = std::chrono::duration_cast<std::chrono::microseconds>(start - start0);
	
	std::cout << "Time taken by normal search: " << duration3.count() << " microseconds" << std::endl;
	std::cout << "Time taken by function quick sort: "  << duration.count() << " microseconds" << std::endl;
	std::cout << "Time taken by function binary search: " << duration2.count() << " microseconds" << std::endl;
	return 0;	
}
