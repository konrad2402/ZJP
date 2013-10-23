#include <stdio.h>
#include <math.h>
#include "mpi.h"
#include <time.h>

#define N 1000000
#define X -2
#define Y 2

double f (double x){
	return pow(M_E, -x*x);
}

int main(int argc, char **argv) {
    clock_t start, stop;
	start=clock();
    int rank, namelen, size, n=atoi(argv[1]);
    char host[100];
    double x=atoi(argv[2]), time;
    double y=atoi(argv[3]);
    int a;
    double calka = 0 ;
    double h = (y-x)/n;
    double suma=0;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Get_processor_name(host,&namelen);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
	if(size == 1){
		for(a=1;a<(n-1);a++){
			calka += (f(x+a*h) + f(x+(a+1.0)*h))/2.0;
		}
		calka = calka * h;
		printf("\nCalka dla x=(%.0f;%.0f) i n=%d wynosi: %f \n", x, y, atoi(argv[1]), suma);
	}
	else {
		if (rank != 0) {
			size = size - 1;
			int begin = (rank-1)*n/size;
			int end = (rank)*n/size;        
			for(a=begin;a<end;a++){
				calka += (f(x+a*h) + f(x+(a+1.0)*h))/2.0;
			}
			calka = calka * h;
			MPI_Reduce(&calka, &suma, 1, MPI_DOUBLE, MPI_SUM, 0,MPI_COMM_WORLD);
		}
		else {
			MPI_Reduce(&calka, &suma, 1, MPI_DOUBLE, MPI_SUM, 0,MPI_COMM_WORLD);
			printf("\nCalka dla x=(%.0f;%.0f) i n=%d wynosi: %f \n", x, y, atoi(argv[1]), suma);
			stop=clock();
			time=(stop - start);
			printf("Czas wykonania algorytmu to: %ld\n", stop-start);
		}
	}
    MPI_Finalize();
    return 0;
}
