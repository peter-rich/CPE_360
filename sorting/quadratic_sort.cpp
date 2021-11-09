#include <assert.h>
#include <iostream>
#include <math.h> 
#include <stdio.h> 
#include <string.h>

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// A function to implement bubble sort
void bubble_sort(int *arr, int n)
{
	//For every pair of adjacent elements, swap the bigger one to the larger index
}



/* Function to sort an array using insertion sort*/
void insertion_sort(int *arr, int n) 
{ 
	//Scan through the array, and track the smallest element of current array
	//Move the smallest element to the top
} 

void selection_sort(int *arr, int n) 
{ 
 	//For a given element, all the elements w/ smaller indices are sorted
	//We want to insert this element into the correct spot
} 


// Driver code
int main(int args, char **argv)
{
    std::cout<<"/path/to/exe count\n";
    assert(args>1);
    int count = atoi(argv[1]);

    int *array_bubble = new int[count];
    int *array_select = new int[count];
    int *array_insert = new int[count];

    for(int i = 0; i < count; i ++)
    {
        int tmp = rand()%23425345;
        array_bubble[i] = tmp;
        array_select[i] = tmp;
        array_insert[i] = tmp;

    }

    bubble_sort(array_bubble, count);
    insertion_sort(array_insert, count);
    selection_sort(array_select, count);

    
    assert(memcmp(array_bubble,array_insert,sizeof(int)*count) == 0);
    assert(memcmp(array_bubble,array_select,sizeof(int)*count) == 0);

    
    std::cout<<"The sorting results match!\n";
}

