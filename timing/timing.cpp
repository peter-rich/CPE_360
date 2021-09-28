#ifndef __TIME_H__
#define __TIME_H__

#include <sys/time.h>
#include <stdlib.h>

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


int main(int args, char **argv){
	double time_begin = wtime();
	
	//Insert the applications we want to measure the time consumption
	//...
	//Matrix multiplication
	//Qsort
	//Binary Search
	//Linear Search
	
	double my_time = wtime() - time_begin;

	std::cout<<"The time consumption is: "<<my_time<<" second(s).\n";
}
