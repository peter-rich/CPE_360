/* C program for Merge Sort */
#include <stdio.h> 
#include <stdlib.h> 
#include <iostream>


// Merges two subarrays of arr[]. 
// First subarray is arr[l..m] 
// Second subarray is arr[m+1..r] 
void merge(int arr[], int l, int m, int r) 
{ 
	//Merging two sorted arrays
} 


/* l is for left index and r is right index of the 
sub-array of arr to be sorted */
void merge_sort(int arr[], int l, int r) 
{ 
	if (l < r) { 
		// Same as (l+r)/2, but avoids overflow for 
		// large l and h 
		int m = l + (r - l) / 2; 

		// Sort first and second halves 
		merge_sort(arr, l, m); 
		merge_sort(arr, m + 1, r); 

		merge(arr, l, m, r); 
	} 
} 

int main(int args, char **argv)
{
    std::cout<<"/path/to/exe count\n";
    assert(args>1);
    int count = atoi(argv[1]);

    int *array = new int[count];
    //int *array_select = new int[count];
    //int *array_insert = new int[count];

    for(int i = 0; i < count; i ++)
    {
        int tmp = rand()%23425345;
        array[i] = tmp;

    }

    merge_sort(array,0, count-1);

    for(int i = 0; i < count - 1; i ++)
        assert(array[i+1]>=array[i]);
    
    std::cout<<"The array is sort in ascending order!\n";
}

