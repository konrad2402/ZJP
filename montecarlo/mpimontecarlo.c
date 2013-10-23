#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "mpi.h"
#include<time.h>

int main(int argc, char **argv) {
    clock_t start, stop;
	start=clock();
	int rank,timee;
	int i;
	int size;
	long int n=atoi(argv[1]);
	double x,y;
	int count=0;
	double z;
	double pi;
	double suma=0;
	
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	srand(time(NULL)); // zapewnia losowanie roznych liczb
	if (rank != 0) {
		size=size-1;
	    int begin = (rank-1)*n/size;
		int end = (rank)*n/size;        
		for (i=begin; i<end; i++) {
			x = (double)rand()/RAND_MAX;
			y = (double)rand()/RAND_MAX;
			z = x*x+y*y;
			if (z<=1) count++;
		}		
		suma=(double)count/n*4;
		MPI_Reduce(&suma,    &pi, 1,  MPI_DOUBLE, MPI_SUM, 0,MPI_COMM_WORLD);
	}
	else {
		MPI_Reduce(&suma,    &pi, 1,  MPI_DOUBLE, MPI_SUM, 0,MPI_COMM_WORLD);
		printf("\nPi wynosi: %f dla n=%d\n" ,pi, atoi(argv[1]));   
		stop=clock();
		timee=(stop - start);
		printf("Czas wykonania algorytmu to: %ld\n", stop-start); 
	}
	MPI_Finalize();
	return 0;
}