#include <iostream>
#include <chrono>


void bubble_sort(int* a, int n)
{
;	
}

int main(){
	int * array = {23, 78, 45, 8, 32, 56};
 	auto start = std::chrono::high_resolution_clock::now();	
	
	auto end = std::chrono::high_resolution_clock::now();

	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	
	std::cout << "Time taken by bubble sort: " << duration.count() << " microseconds" << std::endl;

	return 0;
}
