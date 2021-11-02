#include <iostream>
#include <stdlib.h>
#define HEAP_LIMIT (1<<20)
//Since a heap is a complete binary tree, we use arrays, instead of pointer-based structs to implement.

//provided
void 
insert_heap (int *my_heap, int &my_heap_size, int val){
	my_heap_size ++;
	if(my_heap_size >= HEAP_LIMIT){
		std::cout<<"HEAP OVERFLOW\n";
		exit(-1);
	}

	my_heap[my_heap_size] = val;

	//Promote this newly inserted element (comparing it w/ its parents and potentially swap them until we cannot swap any more).
	//So the problem becomes: How to find one element's parent after we know its index

}

//Finish this during the class
int
delete_min_heap (int *heap){

}

//Try this 
void 
build_heap (int *heap, int *array, int size){

}


int main (int args, char **argv){
	std::cout<<"/path/to/exe array_size\n";

	if(args<=1){
	
		std::cout<<"Wrong input # of arguments\n";
		exit;
	}

	int *my_heap = new int[HEAP_LIMIT]; 
	int my_heap_size = 0;


	int array_size = atoi(argv[1]);

	int *array = new int[array_size];

	//This array should contain no duplicates
	for(int i = 0; i < array_size; i ++)
	{
		int num = rand()%100;
		array[i] = num;
		
		for(int j = 0; j < i; j ++)
			if(num == array[j])
			{
				i--;
				break;
			}
	}
	
	for(int i = 0; i < array_size; i ++)
		insert_heap(my_heap, my_heap_size, array[i]);
	
} 
